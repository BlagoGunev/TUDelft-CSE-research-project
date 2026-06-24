from vllm import LLM, SamplingParams
from pathlib import Path

path = ("/Users/bgunev/.cache/huggingface/hub/models--unsloth--Qwen3.5-4B-GGUF/" + 
    "snapshots/e87f176479d0855a907a41277aca2f8ee7a09523/Qwen3.5-4B-Q4_K_M.gguf")

# in_path = "./in/cpp/"
# out_path = "./out/java/"

# in_path = "/Volumes/APFS Ex/cpp/"
# out_path = "/Volumes/APFS Ex/java/"

in_path = "/Volumes/APFS Ex/cpp/"
out_path = "/Volumes/APFS Ex/java/"

src_language = "C++"
dst_language = "Java"
# prompt = f"Translate this {src_language} code to {dst_language}. The filename is {{filename}}. Output only the resulting program.\n"
prompt = f"Translate this {src_language} code to {dst_language}. The output filename is {{filename}}. Output only the resulting program.\n"
prompt_planning = (f"Translate this {src_language} code to {dst_language}. The output filename is {{filename}}. First, make a plan for the translation " + 
                   f"by considering what are {src_language} specific features and how they could be translated. Also consider whether the work could be " + 
                   f"split up in small incremental tasks. Then, output the resulting program with token \"<CODE>\" at the beginning and at the end.\n")

def generate_responses(llm: LLM, inputs):
    sp = SamplingParams(
        temperature=0.6, top_p=0.95, top_k=20, min_p=0.0, presence_penalty=0.0, repetition_penalty=1.0,
        max_tokens=30000
    )
    # sp = SamplingParams(temperature=0.8, top_p=0.95)

    errors = []
    for idx, i in enumerate(inputs):
        if idx % 20 == 0:
            print(f"Wrote {idx} files.")
        # outputs.append(llm.create_chat_completion(
        filename = i["filename"]
        file_java = filename.split(".")[0] + ".java"
        file_out_simple = Path(out_path).joinpath("simple", file_java)
        file_out_plan = Path(out_path).joinpath("plan", file_java)
        file_out_plan_misc = Path(out_path).joinpath("plan", filename.split(".")[0] + ".plan")
        if file_out_simple.exists():
            print(f"Found {file_java}, skipping.")
            continue
        try:
            prompts = [
                prompt.format(filename=file_java) + i["file_content"],
                prompt_planning.format(filename=file_java) + i["file_content"],
            ]
            print(prompts)
            out = llm.generate(prompts, sp)
            # print(out)
            out_simple = out[0]
            out_plan = out[1]
            java_simple_code = out_simple.outputs[0].text
            temp = out_plan.outputs[0].text.split("<CODE>")
            java_plan_plan = temp[0]
            java_plan_code = temp[1]
            with (open(file_out_simple, "w") as fs, open(file_out_plan, "w") as fp, 
                  open(file_out_plan_misc) as fp_misc):
                fs.write(java_simple_code)
                fp.write(java_plan_code)
                fp_misc.write(java_plan_plan)
        except Exception as e:
            # errors.append(e)
            print(e)

        # for idx, out in enumerate(outputs):
        # print(out)
        # print(out["message"]["content"])
        
    return errors

def main():
    # Generate paths
    Path(out_path).joinpath("simple").mkdir(parents=True, exist_ok=True)
    Path(out_path).joinpath("plan").mkdir(parents=True, exist_ok=True)

    # llm = LLM(model="facebook/opt-125m", gpu_memory_utilization=0.22)
    llm = LLM(model="facebook/opt-125m", gpu_memory_utilization=0.22)

    inputs = []
    for idx, file in enumerate(Path(in_path).iterdir()):
        if idx % 100 == 0:
            print(f"Loaded {idx} files.")
        with open(file, "r") as f:
            inputs.append({
                # "prompt": prompt.format(filename=file.name) + f.read(),
                "file_content": f.read(),
                "filename": file.name
            })
        break

    # print(inputs)

    # Create out dir
    if not Path(out_path).exists():
        print(f"Creating out path at: {Path(out_path).absolute()}")
        Path(out_path).mkdir(parents=True, exist_ok=True)

    # Generate responses
    errors = generate_responses(llm, inputs)
    print(errors)

    # Write translated programs to out dir
    # for idx, out in enumerate(outputs):
    #     # print(out)
    #     # print(out["message"]["content"])
    #     filename = inputs[idx]["filename"]
    #     if idx % 20 == 0:
    #         print(f"Wrote {idx+1} files.")
    #     with open(out_path + filename.split(".")[0] + ".java", "w") as f:
    #         f.write(out["choices"][0]["message"]["content"])

if __name__ == "__main__":
    main()