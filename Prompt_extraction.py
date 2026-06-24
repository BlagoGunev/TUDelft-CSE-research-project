from __future__ import annotations

import argparse
import re
import shutil
from dataclasses import dataclass
from pathlib import Path


DEFAULT_ROOT = Path("/Volumes/APFS Ex/delftblue/java")
SIMPLE_SOURCE_DIR = "simple"
PLAN_SOURCE_DIR = "plan"

SIMPLE_OUT_DIR = "out_simple"
PLAN_CODE_OUT_DIR = "out_plan_code"
PLAN_TEXT_OUT_DIR = "out_plan_text"

JAVA_FENCE_RE = re.compile(r"```(?P<lang>[^\n`]*)\n(?P<body>.*?)```", re.DOTALL)
PLAN_CODE_RE = re.compile(r"<CODE>(?P<body>.*?)</CODE>", re.DOTALL)
JAVA_START_RE = re.compile(r"(?m)^(import\s+java\.|import\s+javax\.|public\s+class\s+|class\s+\w+\s*\{)")
JAVA_MARKERS = (
	"import java.",
	"public class",
	"public static void main",
	"system.out",
	"stringbuilder",
)

CPLUSPLUS_MARKERS = (
	"#include",
	"using namespace std",
	"template<",
	"std::",
	"printf(",
	"scanf(",
	"freopen(",
	"class fast_input",
	"class fast_reader",
	"fread(",
)


@dataclass
class ExtractionError:
	source: Path
	message: str


@dataclass
class ExtractionStats:
	total: int = 0
	successful: int = 0
	failed: int = 0


def recreate_directory(path: Path) -> None:
	if path.exists():
		shutil.rmtree(path)
	path.mkdir(parents=True, exist_ok=True)


def read_text(path: Path) -> str:
	return path.read_text(encoding="utf-8", errors="replace")


def write_text(path: Path, content: str) -> None:
	path.parent.mkdir(parents=True, exist_ok=True)
	path.write_text(content, encoding="utf-8")


def trim_to_java_body(text: str) -> str:
	cleaned = re.sub(r"(?m)^\s*<CODE>\s*$\n?", "", text)
	cleaned = re.sub(r"(?m)^\s*</CODE>\s*$\n?", "", cleaned)
	cleaned = cleaned.strip()
	start_match = JAVA_START_RE.search(cleaned)
	if start_match is None:
		return cleaned.strip()
	cleaned = cleaned[start_match.start():].strip()
	stop_match = re.search(r"</think>|### Translation Plan|### Java Code|### Plan for Translation|Here is the plan|Here is the code", cleaned)
	if stop_match is not None:
		cleaned = cleaned[:stop_match.start()].strip()
	cleaned = re.sub(r"(?m)^\s*<CODE>\s*$\n?", "", cleaned)
	cleaned = re.sub(r"(?m)^\s*</CODE>\s*$\n?", "", cleaned)
	return cleaned.strip()


def looks_like_java(text: str) -> bool:
	lower = text.lower()
	java_pos = None
	for marker in JAVA_MARKERS:
		pos = lower.find(marker)
		if pos != -1 and (java_pos is None or pos < java_pos):
			java_pos = pos
	cpp_pos = None
	for marker in CPLUSPLUS_MARKERS:
		pos = lower.find(marker)
		if pos != -1 and (cpp_pos is None or pos < cpp_pos):
			cpp_pos = pos
	if java_pos is None:
		return False
	if cpp_pos is None:
		return True
	return java_pos <= cpp_pos


def select_simple_java_block(text: str) -> str | None:
	blocks: list[tuple[int, str, str]] = []
	for index, match in enumerate(JAVA_FENCE_RE.finditer(text)):
		lang = match.group("lang").strip().lower()
		body = match.group("body").strip("\n")
		blocks.append((index, lang, body))

	if not blocks:
		start_match = JAVA_START_RE.search(text)
		if start_match is None:
			return None
		return text[start_match.start():].strip()

	def block_score(item: tuple[int, str, str]) -> tuple[int, int]:
		index, lang, body = item
		score = 0
		if lang in {"java", "code"}:
			score += 4
		if "public static void main" in body:
			score += 3
		if "class " in body:
			score += 2
		if "System.out" in body:
			score += 1
		return score, index

	best = max(blocks, key=block_score)
	if block_score(best)[0] == 0:
		return None
	return trim_to_java_body(best[2])


def select_plan_code_segment(text: str) -> tuple[tuple[int, int], str] | None:
	# Simplified detection: only accept an explicit <CODE>...</CODE> block
	# (case-insensitive) where the closing token is at the end of the input
	# (ignoring trailing whitespace), or the variant where the file ends with
	# a second <CODE> token used as a closing marker.
	txt = text
	stripped = txt.rstrip()

	# Case A: standard closing tag </CODE> at end
	if re.search(r"(?i)</code>\s*$", txt):
		# find the last opening <CODE> (case-insensitive)
		opens = list(re.finditer(r"(?i)<code>", txt))
		if not opens:
			return None
		last_open = opens[-1]
		close_match = re.search(r"(?i)</code>\s*$", txt)
		if not close_match:
			return None
		body = txt[last_open.end():close_match.start()]
		return (last_open.start(), close_match.end()), trim_to_java_body(body)

	# Case B: variant where the file ends with another <CODE> token used as closing
	if stripped.lower().endswith("<code>"):
		opens = list(re.finditer(r"(?i)<code>", txt))
		if len(opens) < 2:
			return None
		open_match = opens[-2]
		close_match = opens[-1]
		body = txt[open_match.end():close_match.start()]
		return (open_match.start(), close_match.end()), trim_to_java_body(body)

	return None


def extract_simple_java(text: str) -> tuple[str | None, str | None]:
	code = select_simple_java_block(text)
	if code is None:
		return None, "no Java code block or Java-like code snippet found"
	if not code.strip():
		return None, "Java code block was empty"
	return code.strip() + "\n", None


def extract_plan_parts(text: str) -> tuple[str | None, str | None, str | None]:
	selection = select_plan_code_segment(text)
	if selection is None:
		return None, None, "missing code block or <CODE>...</CODE> segment"

	(start, end), code = selection
	if not code:
		return None, None, "selected code segment was empty"
	if not looks_like_java(code):
		return None, None, "selected code segment does not look like Java"

	plan_text = (text[:start] + text[end:]).strip()
	if not plan_text:
		return None, None, "no plan text found outside the <CODE> block"

	return code.strip() + "\n", plan_text + "\n", None


def process_simple_directory(root: Path, out_dir: Path) -> tuple[list[ExtractionError], ExtractionStats]:
	errors: list[ExtractionError] = []
	stats = ExtractionStats()
	source_dir = root / SIMPLE_SOURCE_DIR

	for source in sorted(source_dir.iterdir()):
		if not source.is_file() or source.suffix != ".java":
			continue
		stats.total += 1

		destination = out_dir / f"{source.stem}.java"
		try:
			code, error = extract_simple_java(read_text(source))
			if error is not None or code is None:
				errors.append(ExtractionError(source=source, message=error or "unknown extraction failure"))
				stats.failed += 1
				continue
			write_text(destination, code)
			stats.successful += 1
		except Exception as exc:  # pragma: no cover - defensive guard for malformed conversations.
			errors.append(ExtractionError(source=source, message=f"unexpected failure: {exc}"))
			stats.failed += 1

	return errors, stats


def process_plan_directory(root: Path, code_out_dir: Path, text_out_dir: Path) -> tuple[list[ExtractionError], ExtractionStats]:
	errors: list[ExtractionError] = []
	stats = ExtractionStats()
	source_dir = root / PLAN_SOURCE_DIR

	for source in sorted(source_dir.iterdir()):
		if not source.is_file() or source.suffix != ".java":
			continue
		stats.total += 1

		code_destination = code_out_dir / f"{source.stem}.java"
		text_destination = text_out_dir / f"{source.stem}.txt"
		try:
			code, plan_text, error = extract_plan_parts(read_text(source))
			if error is not None or code is None or plan_text is None:
				errors.append(ExtractionError(source=source, message=error or "unknown extraction failure"))
				stats.failed += 1
				continue
			write_text(code_destination, code)
			write_text(text_destination, plan_text)
			stats.successful += 1
		except Exception as exc:  # pragma: no cover - defensive guard for malformed conversations.
			errors.append(ExtractionError(source=source, message=f"unexpected failure: {exc}"))
			stats.failed += 1

	return errors, stats


def write_errors(path: Path, errors: list[ExtractionError]) -> None:
	lines = [f"{error.source.name}: {error.message}" for error in errors]
	write_text(path, "\n".join(lines) + ("\n" if lines else ""))


def write_results(path: Path, simple_stats: ExtractionStats, plan_stats: ExtractionStats) -> None:
	def percentage(stats: ExtractionStats) -> float:
		return 0.0 if stats.total == 0 else (stats.successful * 100.0) / stats.total

	lines = [
		"simple:",
		f"  input files: {simple_stats.total}",
		f"  correct: {simple_stats.successful}",
		f"  incorrect: {simple_stats.failed}",
		f"  correct percentage: {percentage(simple_stats):.2f}%",
		"plan:",
		f"  input files: {plan_stats.total}",
		f"  correct: {plan_stats.successful}",
		f"  incorrect: {plan_stats.failed}",
		f"  correct percentage: {percentage(plan_stats):.2f}%",
	]
	write_text(path, "\n".join(lines) + "\n")


def build_parser() -> argparse.ArgumentParser:
	parser = argparse.ArgumentParser(description="Extract Java code and plan text from conversation files.")
	parser.add_argument("--root", type=Path, default=DEFAULT_ROOT, help="Root folder that contains plan/ and simple/")
	return parser


def main() -> int:
	args = build_parser().parse_args()
	root: Path = args.root

	simple_source = root / SIMPLE_SOURCE_DIR
	plan_source = root / PLAN_SOURCE_DIR
	if not simple_source.exists():
		raise FileNotFoundError(f"missing source directory: {simple_source}")
	if not plan_source.exists():
		raise FileNotFoundError(f"missing source directory: {plan_source}")

	simple_out = root / SIMPLE_OUT_DIR
	plan_code_out = root / PLAN_CODE_OUT_DIR
	plan_text_out = root / PLAN_TEXT_OUT_DIR

	recreate_directory(simple_out)
	recreate_directory(plan_code_out)
	recreate_directory(plan_text_out)

	simple_errors, simple_stats = process_simple_directory(root, simple_out)
	plan_errors, plan_stats = process_plan_directory(root, plan_code_out, plan_text_out)

	write_errors(root / "simple_errors.txt", simple_errors)
	write_errors(root / "plan_errors.txt", plan_errors)
	write_results(root / "prompt_extraction_results.txt", simple_stats, plan_stats)

	print(f"Wrote {len(list(simple_out.iterdir()))} simple code files.")
	print(f"Wrote {len(list(plan_code_out.iterdir()))} plan code files.")
	print(f"Wrote {len(list(plan_text_out.iterdir()))} plan text files.")
	print(f"Recorded {len(simple_errors)} simple errors and {len(plan_errors)} plan errors.")
	return 0


if __name__ == "__main__":
	raise SystemExit(main())
