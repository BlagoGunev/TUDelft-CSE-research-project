from datasets import load_dataset
from pathlib import Path

ds_path = "/Volumes/APFS Ex/generated_tests/"
test_path = "/Volumes/APFS Ex/tests/"

ds = load_dataset(
    "open-r1/codeforces",
    # name="verifiable",
    streaming=True,
    split="test"
)

def main():
    # print(ds)
    written = 0
    for en in ds:
        # print(en)
        contest_id = en["contest_id"]
        pr = en["index"].lower()
        filename = f"{pr}_{contest_id}"
        # print(filename)
        if filename == "c_454" or filename == "c_440" or filename == "a2_177" or filename == "g3_513":
            print(en)
            continue
        else:
            continue
        if not en["official_tests_complete"] or en["input_mode"] != "stdio" or Path(test_path).joinpath("in", filename).exists():
            continue

        test_in_path = Path(test_path).joinpath("in", filename)
        test_in_path.mkdir(parents=True, exist_ok=True)
        test_out_path = Path(test_path).joinpath("out", filename)
        test_out_path.mkdir(parents=True, exist_ok=True)
        
        for idx, test in enumerate(en["official_tests"], start=1):
            tin = test["input"]
            tout = test["output"]
            with open(test_in_path.joinpath(f"{idx}.in"), "w") as f:
                f.write(tin)
            with open(test_out_path.joinpath(f"{idx}.out"), "w") as f:
                f.write(tout)
        written += 1
        
        if written % 20 == 0:
            print(f"Written {written} tests.")

if __name__ == "__main__":
    main()
    