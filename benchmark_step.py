from pathlib import Path
import subprocess

in_path = "./in/cpp/"
out_path = "./out/java/"
test_in_path = "./tests/in/"
test_out_path = "./tests/out/"
test_generated_out_path = "./tests/gen/"

src_language = "C++"
dst_language = "Java"

def main():

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


    # difflib
    # filecmp(file1, file2)
    # dircmp
    # java -cp out_dir file

    # if not Path(test_generated_out_path).exists():
    #     print("Generating test results out folder.")
    #     Path(test_generated_out_path).mkdir(parents=True, exist_ok=True)

    success = []
    fail = []
    other = []
    for c in compiled:
        basename = c["filename"].replace(".java", "")
        classname = c["filename"] + ".class"
        # print(classname)
        test_in = Path(test_in_path + basename)
        if not test_in.exists() or test_in.is_dir():
            other.append({"filename": classname, "error": "Dir not found"})

        test_gen_out = Path(test_generated_out_path + basename + '/')
        if not test_gen_out.exists():
            test_gen_out.mkdir(parents=True, exist_ok=True)

        for test in test_in.iterdir():
            outname = test.name.replace(".in", ".out")
            with open(test) as sin, open(test_gen_out.joinpath(outname), "w") as sout:
                subprocess.run(["java", "-cp", out_path, basename], stdin=sin, stdout=sout)

if __name__ == "__main__":
    main()