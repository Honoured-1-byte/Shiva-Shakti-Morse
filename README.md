Markdown
# 🕉️ Shiva-Shakti Morse Code: Devanagari Huffman Compression

This project explores the intersection of Information Theory, Data Structures, and Ancient Linguistics. It processes verses from sacred Indian texts to mathematically determine the frequency distribution of the Devanagari script, compressing the language into a custom, prefix-free binary encoding (a "Sanskrit Morse Code").

## 🧠 The "Shiva-Shakti" Concept
Unlike standard Huffman coding which arbitrarily assigns `0` (left) and `1` (right) to tree branches, this algorithm applies a philosophical constraint based on Sanskrit linguistics:
* **Shiva (Consciousness / Vowels):** All independent vowels and *matras* are strictly routed to the **Left** branches (represented by a Dot `.`).
* **Shakti (Energy / Consonants):** All base consonants are strictly routed to the **Right** branches (represented by a Dash `-`).

The result is a mathematically optimized tree where the most frequently used structural elements (like the *Halant* `्` and the `ा` matra) have the shortest codes, while maintaining strict phonetic separation.

## 📊 The Dataset
The original text corpus was extracted from a structured JSON dataset containing over 100,000 verses from the Vedas, Upanishads, and Epics. 

*(Note: To keep this repository lightweight, the massive JSON directories have been omitted. A `sample_corpus.txt` containing verses from the Bhagavad Gita is included for immediate testing.)*

## 🛠️ Tech Stack
* **Node.js:** Used for deep recursive JSON parsing to extract raw text strings from deeply nested datasets.
* **C++:** Handles the heavy lifting—UTF-8 byte parsing, O(1) Hash Mapping, O(n log n) Min-Heap tree building, and Two-Way Translation.
* **Graphviz:** Used to generate a visual SVG/DOT map of the resulting algorithm.
* **Python:** Uses `winsound` to audibly play the generated Sanskrit Morse codes.

## 🚀 How to Run the Project

### 1. The C++ Translator
Encode any Devanagari string into the new Shiva-Shakti Morse code, or decode the dots and dashes back into Sanskrit!
Compile and run the translator:
```bash
g++ translator.cpp -o translator
translator.exe
2. Build the Tree & Generate Codes
To run the full algorithm and rebuild the tree from the sample_corpus.txt:

Bash
g++ shiva_shakti_tree.cpp -o shiva_tree -O3
shiva_tree.exe
(This outputs the code dictionary to shiva_shakti_codes.txt and the visual map to shiva_shakti_tree.dot).

3. Visualize the Algorithm
Copy the contents of shiva_shakti_tree.dot and paste them into WebGraphviz or Edotor.net to see the sweeping binary tree of the language.

📝 Example Output
The algorithm mathematically proves the efficiency of Sanskrit morphology. For example, the Halant (्), which is used constantly to create conjunct consonants, is awarded the shortest possible code: ---.

य: ..-.-

श: -....-

यश: ..-.- -....-

## 🙏 Acknowledgments & Data Source
The raw Sanskrit and Awadhi verses used to generate the frequency distributions for this algorithm were sourced from the excellent [DharmicData repository](https://github.com/bhavykhatri/DharmicData) by bhavykhatri. This project utilizes their compiled JSON datasets of Hindu sacred texts under the Open Database License (ODbL).
