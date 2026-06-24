from llama_cpp import Llama
from transformers import pipeline, BitsAndBytesConfig
from accelerate import Accelerator
from pathlib import Path
import torch

device = Accelerator().device

in_path = "/scratch/bgunev/sources/cpp/"
out_path = "/scratch/bgunev/sources/trans/java/"

src_language = "C++"
dst_language = "Java"

prompt = f"Translate this {src_language} code to {dst_language} code. The main class name should be {{classname}}. Output only the code of the resulting program.\n"
prompt_planning = (f"Translate this {src_language} code to {dst_language} code. The main class name should be {{classname}}. First, make a plan for the translation " + 
                   f"by considering what are {src_language} specific features and how they could be translated. Also consider whether the work could be " + 
                   f"split up in small incremental tasks. Then, output the code of the resulting program with token \"<CODE>\" at the beginning and at the end.\n")

def get_llama_response(llm: Llama, prompts: list[str]):
    responses = []
    for p in prompts:
        responses.append(llm.create_chat_completion(
                messages=[{
                    "role": "user",
                    "content": p,
                }], # Prompt
                max_tokens=30000, 
            )["choices"][0]["message"]["content"])
    return responses

def get_transformers_response(llm: pipeline, prompts: list[str]):
    sampling_params = {
        "temperature":0.6, 
        "top_p":0.95, 
        "top_k":20, 
        "min_p":0.0, 
        "repetition_penalty":1.0,
    }
    return [x[0]["generated_text"] for x in llm(prompts, max_new_tokens=30000, **sampling_params)]


def generate_responses(llm: pipeline, inputs):
    errors = []
    for idx, i in enumerate(inputs):
        if idx % 20 == 0:
            print(f"Wrote {idx} files.")
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
                prompt.format(classname=filename.split(".")[0]) + i["file_content"],
                prompt_planning.format(classname=filename.split(".")[0]) + i["file_content"],
            ]
            responses = get_transformers_response(llm, prompts)
            out_simple = responses[0]
            out_plan = responses[1]
            print(out_simple, out_plan)
            java_simple_code = out_simple
            java_plan_code = out_plan
            with (open(file_out_simple, "w") as fs, open(file_out_plan, "w") as fp):
                fs.write(java_simple_code)
                fp.write(java_plan_code)
        except Exception as e:
            print(e)
        
    return errors

def main():
    # Generate paths
    Path(out_path).joinpath("simple").mkdir(parents=True, exist_ok=True)
    Path(out_path).joinpath("plan").mkdir(parents=True, exist_ok=True)

    quantization_config = BitsAndBytesConfig(
        load_in_4bit=True,
        bnb_4bit_compute_dtype=torch.bfloat16,
        bnb_4bit_quant_type="nf4",
        bnb_4bit_use_double_quant=True,
    )


    llm = pipeline(
        "text-generation",
        model="/scratch/bgunev/qwen-9b/",
        device=device,
        model_kwargs={
            "quantization_config": quantization_config,
            "torch_dtype": torch.bfloat16,
        }
    )

    inputs = []
    for idx, file in enumerate(Path(in_path).iterdir()):
        if idx % 100 == 0:
            print(f"Loaded {idx} files.")
        with open(file, "r") as f:
            inputs.append({
                "file_content": f.read(),
                "filename": file.name
            })

    # Create out dir
    if not Path(out_path).exists():
        print(f"Creating out path at: {Path(out_path).absolute()}")
        Path(out_path).mkdir(parents=True, exist_ok=True)

    # Generate responses
    errors = generate_responses(llm, inputs)
    print(errors)

if __name__ == "__main__":
    main()
