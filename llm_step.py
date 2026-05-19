from llama_cpp import Llama
from pathlib import Path

path = ("/Users/bgunev/.cache/huggingface/hub/models--unsloth--Qwen3.5-4B-GGUF/" + 
    "snapshots/e87f176479d0855a907a41277aca2f8ee7a09523/Qwen3.5-4B-Q4_K_M.gguf")

in_path = "./in/cpp/"
out_path = "./out/java/"

src_language = "C++"
dst_language = "Java"
prompt = f"Translate this {src_language} code to {dst_language}. The filename is {{filename}}. Output only the resulting program.\n"

def generate_responses(llm: Llama, inputs):
    outputs = []
    for i in inputs:
        outputs.append(llm.create_chat_completion(
            messages=[{
                "role": "user",
                "content": i["prompt"],
            }], # Prompt
            max_tokens=3000, # Generate up to 32 tokens, set to None to generate up to the end of the context window
            #   stop=["Q:", "\n"], # Stop generating just before the model would generate a new question
            #   echo=True # Echo the prompt back in the output
            
        ))
    return outputs

def main():
    llm = Llama(
        model_path=path,
        n_gpu_layers=-1, # Uncomment to use GPU acceleration
        # seed=1337, # Uncomment to set a specific seed
        n_ctx=8192, # Uncomment to increase the context window
        verbose=False,
    )

    inputs = []
    for file in Path(in_path).iterdir():
        with open(file, "r") as f:
            inputs.append({
                "prompt": prompt.format(filename=file.name) + f.read(),
                "filename": file.name
            })

    # print(inputs)

    # Generate responses
    outputs = generate_responses(llm, inputs)
    # print(outputs)

    # Create out dir
    if not Path(out_path).exists():
        print(f"Creating out path at: {Path(out_path).absolute()}")
        Path(out_path).mkdir(parents=True, exist_ok=True)

    # Write translated programs to out dir
    for idx, out in enumerate(outputs):
        # print(out)
        # print(out["message"]["content"])
        filename = inputs[idx]["filename"]
        with open(out_path + filename.split(".")[0] + ".java", "w") as f:
            f.write(out["choices"][0]["message"]["content"])

if __name__ == "__main__":
    main()