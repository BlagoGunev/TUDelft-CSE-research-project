from llama_cpp import Llama
from pathlib import Path

path = ("/Users/bgunev/.cache/huggingface/hub/models--unsloth--Qwen3.5-4B-GGUF/" + 
    "snapshots/e87f176479d0855a907a41277aca2f8ee7a09523/Qwen3.5-4B-Q4_K_M.gguf")

# in_path = "./in/cpp/"
# out_path = "./out/java/"

in_path = "/Volumes/APFS Ex/cpp/"
out_path = "/Volumes/APFS Ex/java/"

src_language = "C++"
dst_language = "Java"
prompt = f"Translate this {src_language} code to {dst_language}. The filename is {{filename}}. Output only the resulting program.\n"

def generate_responses(llm: Llama, inputs):
    errors = []
    for idx, i in enumerate(inputs):
        if idx % 20 == 0:
            print(f"Wrote {idx} files.")
        # outputs.append(llm.create_chat_completion(
        filename = i["filename"]
        file_out = Path(out_path + filename.split(".")[0] + ".java")
        if file_out.exists():
            print(f"Found {file_out.name}, skipping.")
            continue
        try:
            out = llm.create_chat_completion(
                messages=[{
                    "role": "user",
                    "content": i["prompt"],
                }], # Prompt
                max_tokens=30000, # Generate up to 32 tokens, set to None to generate up to the end of the context window
                #   stop=["Q:", "\n"], # Stop generating just before the model would generate a new question
                #   echo=True # Echo the prompt back in the output
                
            )
            with open(file_out, "w") as f:
                f.write(out["choices"][0]["message"]["content"])
        except Exception as e:
            errors.append(e)

        # for idx, out in enumerate(outputs):
        # print(out)
        # print(out["message"]["content"])
        
    return errors

def main():
    llm = Llama(
        model_path=path,
        n_gpu_layers=-1, # Uncomment to use GPU acceleration
        # seed=1337, # Uncomment to set a specific seed
        n_ctx=16384, # Uncomment to increase the context window
        verbose=True,
        # temperature=0.7,
        # top_p=0.8,
        # presence_penalty=1.5,
        # extra_body={
        #     "top_k": 20,
        #     "chat_template_kwargs": {"enable_thinking": False},
        # }, 
    )

    inputs = []
    for idx, file in enumerate(Path(in_path).iterdir()):
        if idx % 100 == 0:
            print(f"Loaded {idx} files.")
        with open(file, "r") as f:
            inputs.append({
                "prompt": prompt.format(filename=file.name) + f.read(),
                "filename": file.name
            })

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