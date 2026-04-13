from airllm import AutoModel

# Load the model (e.g., Llama-3-8B or 70B)
model = AutoModel.from_pretrained("garage-bAInd/Platypus2-70B-instruct")

# Prepare input
input_text = "What is the capital of China?"
input_tokens = model.tokenizer(
    [input_text],
    return_tokens="pt",
    truncation=True,
    max_length=128
)

# Generate output
generation_output = model.generate(
    input_tokens['input_ids'].cuda(),
    max_new_tokens=20,
    use_cache=True
)

# Decode output
output = model.tokenizer.batch_decode(generation_output)
print(output)
