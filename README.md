--Markdown--
# 🕉️ Shiva-Shakti Morse Code: Devanagari Huffman Compression

This project explores the intersection of Information Theory, Data Structures, and Ancient Linguistics. It processes over **100,000 verses** of sacred Indian texts to mathematically determine the frequency distribution of the Devanagari script, compressing the language into a custom, prefix-free binary encoding (a "Sanskrit Morse Code").

## 🧠 The "Shiva-Shakti" Concept
Unlike standard Huffman coding which arbitrarily assigns `0` (left) and `1` (right) to tree branches, this algorithm applies a philosophical constraint based on Sanskrit linguistics:
* **Shiva (Consciousness / Vowels):** All independent vowels and *matras* are strictly routed to the **Left** branches (represented by a Dot `.`).
* **Shakti (Energy / Consonants):** All base consonants are strictly routed to the **Right** branches (represented by a Dash `-`).

The result is a mathematically optimized tree where the most frequently used structural elements have the shortest codes.

## 📊 The Dataset
The text corpus was extracted from a structured JSON dataset containing:
* The Rigveda, Yajurveda, and Atharvaveda
* Srimad Bhagavad Gita
* Valmiki Ramayana & Ramcharitmanas
* The Mahabharata

*(Note: To keep this repository lightweight, the massive JSON directories have been omitted. A `sample_corpus.txt` is included for testing.)*

## 🛠️ Tech Stack
* **Node.js:** Recursive JSON parsing.
* **C++:** UTF-8 byte parsing, O(1) Hash Mapping, and O(n log n) Min-Heap tree building.
* **Graphviz:** Visual SVG/DOT map generation.

## 🚀 How to Run the Project

### 1. The C++ Translator
Encode any Devanagari string into the new Shiva-Shakti Morse code, or decode back into Sanskrit!
```bash
g++ translator.cpp -o translator
./translator
2. Build the Tree & Generate Codes
To run the full algorithm and rebuild the tree from the sample corpus:

Bash
g++ shiva_shakti_tree.cpp -o shiva_tree -O3
./shiva_tree
Outputs: shiva_shakti_codes.txt (dictionary) and shiva_shakti_tree.dot (visual map).

3. Visualize the Algorithm
Copy the contents of shiva_shakti_tree.dot and paste them into WebGraphviz to see the language hierarchy.

📝 Example Output
The algorithm awarding the Halant (्) the shortest code (-..) due to its high structural frequency:

य: ..---

श: .--..-

यश: ..--- .--..-

🙏 Acknowledgments & Data Source
The raw Sanskrit and Awadhi verses were sourced from the DharmicData repository. This project utilizes their compiled JSON datasets under the Open Database License (ODbL).
