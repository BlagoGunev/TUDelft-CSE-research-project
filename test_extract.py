import pyarrow.parquet as pq
from pathlib import Path

ds_path = "/Volumes/APFS Ex/generated_tests/"
test_path = "/Volumes/APFS Ex/tests/"

SIZELIMIT = 300000000

def main():
    sets_path = Path(ds_path)
    in_global_path = Path(test_path + "in")
    # in_global_path.mkdir(parents=True, exist_ok=True)
    out_global_path = Path(test_path + "out")
    # out_global_path.mkdir(parents=True, exist_ok=True)

    skipped = []
    for st in sets_path.iterdir():
        # if st.stat().st_size > SIZELIMIT:
        #     skipped.append(st.name)
        #     continue
        contest_id = int(st.name[11:15])
        ds = pq.read_table(st)
        # print(pq.read_schema(st))
        for batch in ds.to_batches():
            d = batch.to_pydict()
            
            for pid, inp, outp, ti in zip(d["problem_id"], d["input"], d["output"], d["test_i"]):
                # print(f"PID: {pid}")
                # print(inp)
                # print(f"Out:")
                # print(outp)
                # break
                try:
                    # pr = pid[-1].lower()
                    pr = pid.split("/")[-1].lower()
                    # if len(pr) < 2:
                    #     continue
                    path_suffix = f"{pr}_{contest_id}"
                    in_path = in_global_path.joinpath(path_suffix)
                    in_path.mkdir(parents=True, exist_ok=True)
                    out_path = out_global_path.joinpath(path_suffix)
                    out_path.mkdir(parents=True, exist_ok=True)
                    with open(in_path.joinpath(f"{ti}.in"), "w") as f:
                        f.write(inp)
                    with open(out_path.joinpath(f"{ti}.out"), "w") as f:
                        f.write(outp)
                except Exception as e:
                    print(e)

        # break
        

if __name__ == "__main__":
    main()