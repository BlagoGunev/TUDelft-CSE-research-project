from __future__ import annotations

import argparse
import re
import shutil
import subprocess
from dataclasses import dataclass
from pathlib import Path


BENCHMARK_ROOT = Path("/Volumes/APFS Ex/delftblue/java")
TESTS_ROOT = Path("/Volumes/APFS Ex/tests")

SIMPLE_SOURCE_DIR = "out_simple"
PLAN_SOURCE_DIR = "out_plan_code"

COMPILE_SIMPLE_DIR = "compile_simple"
COMPILE_PLAN_DIR = "plan_simple"

SIMPLE_TEST_OUTPUT_DIR = "simple_out"
PLAN_TEST_OUTPUT_DIR = "plan_out"

JAVA_FILE_RE = re.compile(r"^.*\.java$", re.IGNORECASE)
PACKAGE_RE = re.compile(r"(?m)^\s*package\s+([a-zA-Z_][\w.]*)\s*;")


@dataclass
class CompileStats:
	total: int = 0
	compiled: int = 0
	not_compiled: int = 0


@dataclass
class BenchmarkStats:
	tested: int = 0
	correct: int = 0
	incorrect: int = 0


@dataclass
class MiscStats:
	files: int = 0
	total_loc: int = 0
	total_comment_lines: int = 0


def recreate_directory(path: Path) -> None:
	if path.exists():
		shutil.rmtree(path)
	path.mkdir(parents=True, exist_ok=True)


def ensure_directory(path: Path) -> None:
	path.mkdir(parents=True, exist_ok=True)


def read_text(path: Path) -> str:
	return path.read_text(encoding="utf-8", errors="replace")


def write_text(path: Path, content: str) -> None:
	path.parent.mkdir(parents=True, exist_ok=True)
	path.write_text(content, encoding="utf-8")


def list_java_files(path: Path) -> list[Path]:
	if not path.exists():
		return []
	return [file for file in sorted(path.iterdir()) if file.is_file() and JAVA_FILE_RE.match(file.name)]


def source_class_name(source_path: Path) -> str:
	source_text = read_text(source_path)
	package_match = PACKAGE_RE.search(source_text)
	if package_match is None:
		return source_path.stem
	return f"{package_match.group(1)}.{source_path.stem}"


def compile_java_sources(source_dir: Path, compile_dir: Path) -> tuple[CompileStats, list[str], set[str]]:
	stats = CompileStats()
	errors: list[str] = []
	compiled_names: set[str] = set()

	recreate_directory(compile_dir)

	for source_file in list_java_files(source_dir):
		stats.total += 1
		proc = subprocess.run(
			["javac", "-d", str(compile_dir), str(source_file)],
			capture_output=True,
			text=True,
		)
		if proc.returncode == 0:
			stats.compiled += 1
			compiled_names.add(source_file.stem)
			continue

		stats.not_compiled += 1
		error_text = proc.stderr.strip() or proc.stdout.strip() or "unknown compilation error"
		errors.append(f"{source_file.name}:\n{error_text}\n")

	return stats, errors, compiled_names


def compile_result_text(simple_stats: CompileStats, plan_stats: CompileStats) -> str:
	def section(name: str, stats: CompileStats) -> list[str]:
		percentage = 0.0 if stats.total == 0 else (stats.compiled * 100.0) / stats.total
		return [
			f"{name}:",
			f"  inputs: {stats.total}",
			f"  compiled: {stats.compiled}",
			f"  not compiled: {stats.not_compiled}",
			f"  compile percentage: {percentage:.2f}%",
		]

	lines = section("simple", simple_stats) + [""] + section("plan", plan_stats)
	return "\n".join(lines) + "\n"


def count_source_metrics(source_path: Path) -> tuple[int, int]:
	text = read_text(source_path)
	lines = text.splitlines()
	loc = 0
	comment_lines = 0
	in_block_comment = False

	for line in lines:
		stripped = line.strip()
		if not stripped:
			continue

		if in_block_comment:
			comment_lines += 1
			if "*/" in stripped:
				in_block_comment = False
			continue

		if stripped.startswith("//"):
			comment_lines += 1
			continue

		if stripped.startswith("/*"):
			comment_lines += 1
			if "*/" not in stripped:
				in_block_comment = True
			continue

		loc += 1
		if "//" in line or "/*" in line:
			comment_lines += 1

	return loc, comment_lines


def gather_misc_stats(source_dir: Path) -> MiscStats:
	stats = MiscStats()
	for source_file in list_java_files(source_dir):
		loc, comment_lines = count_source_metrics(source_file)
		stats.files += 1
		stats.total_loc += loc
		stats.total_comment_lines += comment_lines
	return stats


def misc_result_text(simple_stats: MiscStats, plan_stats: MiscStats) -> str:
	def average(total: int, files: int) -> float:
		return 0.0 if files == 0 else total / files

	lines = [
		"simple:",
		f"  files: {simple_stats.files}",
		f"  average lines of code: {average(simple_stats.total_loc, simple_stats.files):.2f}",
		f"  average lines of comments: {average(simple_stats.total_comment_lines, simple_stats.files):.2f}",
		"plan:",
		f"  files: {plan_stats.files}",
		f"  average lines of code: {average(plan_stats.total_loc, plan_stats.files):.2f}",
		f"  average lines of comments: {average(plan_stats.total_comment_lines, plan_stats.files):.2f}",
	]
	return "\n".join(lines) + "\n"


def run_program_tests(source_dir: Path, compile_dir: Path, compiled_names: set[str], test_root: Path, output_root: Path) -> tuple[BenchmarkStats, list[str]]:
	stats = BenchmarkStats()
	errors: list[str] = []

	out_dir = output_root / "out"
	err_dir = output_root / "err"
	recreate_directory(output_root)
	ensure_directory(out_dir)
	ensure_directory(err_dir)

	for source_file in list_java_files(source_dir):
		program_name = source_file.stem
		if program_name not in compiled_names:
			continue

		test_input_dir = test_root / "in" / program_name
		expected_output_dir = test_root / "out" / program_name
		if not test_input_dir.exists() or not test_input_dir.is_dir():
			continue

		test_files = [file for file in sorted(test_input_dir.iterdir()) if file.is_file()]
		if not test_files:
			continue

		stats.tested += 1
		program_out_dir = out_dir / program_name
		program_out_dir.mkdir(parents=True, exist_ok=True)
		program_err_file = err_dir / f"{program_name}.err"
		if program_err_file.exists():
			program_err_file.unlink()

		class_name = source_class_name(source_file)
		program_failures: list[str] = []

		for test_file in test_files:
			generated_output = program_out_dir / f"{test_file.stem}.out"
			expected_output = expected_output_dir / f"{test_file.stem}.out"

			with open(test_file, "r", encoding="utf-8", errors="replace") as stdin_handle, \
				open(generated_output, "w", encoding="utf-8") as stdout_handle, \
				open(program_err_file, "a", encoding="utf-8") as stderr_handle:
				try:
					proc = subprocess.run(
						["java", "-cp", str(compile_dir), class_name],
						stdin=stdin_handle,
						stdout=stdout_handle,
						stderr=stderr_handle,
						text=True,
						timeout=5,
					)
				except subprocess.TimeoutExpired:
					program_failures.append(f"{test_file.name}: timeout after 5 seconds")
					stderr_handle.write("timeout after 5 seconds\n")
					continue

			if proc.returncode != 0:
				program_failures.append(f"{test_file.name}: runtime error (exit code {proc.returncode})")
				continue

			if not expected_output.exists():
				program_failures.append(f"{test_file.name}: output mismatch because expected output was missing")
				continue

			generated_text = generated_output.read_text(encoding="utf-8", errors="replace")
			expected_text = expected_output.read_text(encoding="utf-8", errors="replace")
			if generated_text != expected_text:
				program_failures.append(f"{test_file.name}: output mismatch")

		if program_failures:
			stats.incorrect += 1
			errors.append(f"{output_root.name}/{program_name}: " + "; ".join(program_failures))
		else:
			stats.correct += 1

	return stats, errors


def benchmark_result_text(simple_stats: BenchmarkStats, plan_stats: BenchmarkStats) -> str:
	def section(name: str, stats: BenchmarkStats) -> list[str]:
		percentage = 0.0 if stats.tested == 0 else (stats.correct * 100.0) / stats.tested
		return [
			f"{name}:",
			f"  tested: {stats.tested}",
			f"  correct: {stats.correct}",
			f"  incorrect: {stats.incorrect}",
			f"  correct percentage: {percentage:.2f}%",
		]

	lines = section("simple", simple_stats) + [""] + section("plan", plan_stats)
	return "\n".join(lines) + "\n"


def write_error_report(path: Path, title: str, errors: list[str]) -> None:
	lines = [title]
	if errors:
		lines.extend(f"  {entry}" for entry in errors)
	else:
		lines.append("  none")
	write_text(path, "\n".join(lines) + "\n")


def build_parser() -> argparse.ArgumentParser:
	parser = argparse.ArgumentParser(description="Run compilation, correctness, and misc benchmarks for Java outputs.")
	parser.add_argument("--benchmark-root", type=Path, default=BENCHMARK_ROOT, help="Root directory containing out_simple and out_plan_code")
	parser.add_argument("--tests-root", type=Path, default=TESTS_ROOT, help="Root directory containing in/ and out/")
	return parser


def main() -> int:
	args = build_parser().parse_args()
	benchmark_root: Path = args.benchmark_root
	tests_root: Path = args.tests_root

	simple_source_dir = benchmark_root / SIMPLE_SOURCE_DIR
	plan_source_dir = benchmark_root / PLAN_SOURCE_DIR
	if not simple_source_dir.exists():
		raise FileNotFoundError(f"missing source directory: {simple_source_dir}")
	if not plan_source_dir.exists():
		raise FileNotFoundError(f"missing source directory: {plan_source_dir}")
	if not (tests_root / "in").exists():
		raise FileNotFoundError(f"missing test input directory: {tests_root / 'in'}")
	if not (tests_root / "out").exists():
		raise FileNotFoundError(f"missing test output directory: {tests_root / 'out'}")

	compile_simple_dir = benchmark_root / COMPILE_SIMPLE_DIR
	compile_plan_dir = benchmark_root / COMPILE_PLAN_DIR
	simple_test_output_dir = tests_root / SIMPLE_TEST_OUTPUT_DIR
	plan_test_output_dir = tests_root / PLAN_TEST_OUTPUT_DIR

	simple_compile_stats, simple_compile_errors, simple_compiled_names = compile_java_sources(simple_source_dir, compile_simple_dir)
	plan_compile_stats, plan_compile_errors, plan_compiled_names = compile_java_sources(plan_source_dir, compile_plan_dir)

	write_text(benchmark_root / "compile_results.txt", compile_result_text(simple_compile_stats, plan_compile_stats))
	write_error_report(benchmark_root / "compile_simple_errors.txt", "simple compilation errors:", simple_compile_errors)
	write_error_report(benchmark_root / "compile_plan_errors.txt", "plan compilation errors:", plan_compile_errors)

	simple_benchmark_stats, simple_benchmark_errors = run_program_tests(simple_source_dir, compile_simple_dir, simple_compiled_names, tests_root, simple_test_output_dir)
	plan_benchmark_stats, plan_benchmark_errors = run_program_tests(plan_source_dir, compile_plan_dir, plan_compiled_names, tests_root, plan_test_output_dir)

	write_text(benchmark_root / "benchmark_results.txt", benchmark_result_text(simple_benchmark_stats, plan_benchmark_stats))
	write_error_report(
		benchmark_root / "benchmark_errors.txt",
		"benchmark errors:",
		simple_benchmark_errors + plan_benchmark_errors,
	)

	simple_misc_stats = gather_misc_stats(simple_source_dir)
	plan_misc_stats = gather_misc_stats(plan_source_dir)
	write_text(benchmark_root / "misc_results.txt", misc_result_text(simple_misc_stats, plan_misc_stats))

	print(benchmark_result_text(simple_benchmark_stats, plan_benchmark_stats).strip())
	return 0


if __name__ == "__main__":
	raise SystemExit(main())
