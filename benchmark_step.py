from pathlib import Path
import subprocess
from filecmp import dircmp

# in_path = "./in/cpp/"
# out_path = "./out/java/"
# test_in_path = "./tests/in/"
# test_out_path = "./tests/out/"
# test_generated_out_path = "./tests/gen/"

# in_path
out_path = "/Volumes/APFS Ex/java/"
test_in_path = "/Volumes/APFS Ex/tests/in/"
test_out_path = "/Volumes/APFS Ex/tests/out/"
test_generated_out_path = "/Volumes/APFS Ex/tests/gen/"
test_err_path = "/Volumes/APFS Ex/tests/err/"

src_language = "C++"
dst_language = "Java"

def main():
    test_err_out = Path(test_err_path)
    test_err_out.mkdir(parents=True, exist_ok=True)

    compiled = []
    not_compiled = []
    other = []
    # Compile to check syntax
    # TODO: Rewrite with bash scripts to speed up
    for file in Path(out_path).iterdir():
        if not file.is_file():
            continue
        file_ext = file.name.split(".")[-1]
        if not file_ext == 'java':
            continue
        # filename_noext = file.name.split(".")[0]
        proc = subprocess.run(["javac", file.absolute()], capture_output=True)
        if proc.returncode != 0:
            not_compiled.append({"filename": file.name, "error": proc.stderr})
        else:
            compiled.append({"filename": file.name})

    print(f"Compile success rate: {100 * len(compiled) / (len(compiled) + len(not_compiled) + len(other))}%")
    print("Successfully compiled:")
    print(len(compiled))
    print("Error in compilation: ")
    print(len(not_compiled))
    if len(not_compiled) > 0:
        for nc in not_compiled:
            print(nc["filename"])
            print(nc["error"])
            print("")

    success = []
    fail = []
    other = []
    for c in compiled:
        basename = c["filename"].replace(".java", "")
        # classname = basename + ".class"
        # print(classname)
        test_in = Path(test_in_path + basename)
        if not test_in.exists() or test_in.is_file():
            other.append({"filename": basename, "error": "Dir not found"})
            continue
        
        if not any(test_in.iterdir()):
            other.append({"filename": basename, "error": "No tests found"})
            continue

        test_gen_out = Path(test_generated_out_path + basename + '/')
        if not test_gen_out.exists():
            test_gen_out.mkdir(parents=True, exist_ok=True)

        for test in test_in.iterdir():
            outname = test.name.replace(".in", ".out")
            with (open(test) as sin, open(test_gen_out.joinpath(outname), "w") as sout,
                open(test_err_out.joinpath(f"{basename}.err"), "a") as serr):
                subprocess.run(["java", "-cp", out_path, basename], stdin=sin, stdout=sout, stderr=serr, timeout=4)
        
        test_out = Path(test_out_path + basename)
        dcmp = dircmp(test_gen_out, test_out)
        diff_files = dcmp.diff_files
        if len(diff_files):
            fail.append({
                "filename": basename,
                "diff": [f for f in diff_files]
            })
        else:
            success.append({
                "filename": basename
            })
    
    print(f"Test success rate: {len(success) / len(compiled) * 100}%")
    print(f"Success: {len(success)}. Fails: {len(fail)}. Other: {len(other)}.")
    print(success)
    print(fail)
    print(other)


if __name__ == "__main__":
    main()