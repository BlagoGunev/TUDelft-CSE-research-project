from datasets import load_dataset
from pathlib import Path

ds_path = "/Volumes/APFS Ex/"
code_path = "/Volumes/APFS Ex/cpp/"

ds = load_dataset(
    # "open-r1/codeforces-submissions",
    path=ds_path,
    name="selected_accepted",
    streaming=True,
    split="train"
)

def main():
    Path(code_path).mkdir(parents=True, exist_ok=True)

    print(ds)
    for idx, en in enumerate(ds):
        if idx % 20 == 0:
            print(f"Extracted {idx+1} sources.")
        if not "C++" in en["programmingLanguage"]:
            # print(en["programmingLanguage"])
            continue
        
        contestId = en["contestId"]
        problemIndex = en["problem_index"].lower()
        filename = problemIndex + '_' + contestId + ".cpp"
        filepath = Path(code_path).joinpath(filename)
        with open(filepath, "w") as f:
            f.write(en["source"])

if __name__ == "__main__":
    main()