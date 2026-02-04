import os
import pdfplumber
import re

RAW_DIR = "../data_raw"
CLEAN_DIR = "../data_clean"

os.makedirs(CLEAN_DIR, exist_ok=True)

def clean_text(text):
    text = text.lower()
    text = re.sub(r"[^a-z0-9\s]", " ", text)
    text = re.sub(r"\s+", " ", text)
    return text.strip()

for file in os.listdir(RAW_DIR):
    if not file.endswith(".pdf"):
        continue

    pdf_path = os.path.join(RAW_DIR, file)
    out_txt = file.replace(".pdf", ".txt")
    out_path = os.path.join(CLEAN_DIR, out_txt)

    full_text = ""

    with pdfplumber.open(pdf_path) as pdf:
        for page in pdf.pages:
            text = page.extract_text()
            if text:
                full_text += text + "\n"

    cleaned = clean_text(full_text)

    with open(out_path, "w", encoding="utf-8") as f:
        f.write(cleaned)

    print(f"Processed: {file}")
