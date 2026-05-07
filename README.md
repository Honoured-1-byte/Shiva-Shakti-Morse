
# 🕉️ Shiva-Shakti Morse Code: Devanagari Huffman Compression

This project explores the intersection of Information Theory, Data Structures, and Ancient Linguistics. It processes over **100,000 verses** of sacred Indian texts to mathematically determine the frequency distribution of the Devanagari script, compressing the language into a custom, prefix-free binary encoding — a Sanskrit-inspired Morse system.

---

# 🧠 The Shiva–Shakti Principle

Traditional Huffman Coding arbitrarily assigns:

- `0` → Left branch
- `1` → Right branch

This project introduces a philosophical and linguistic constraint inspired by Sanskrit metaphysics:

| Concept | Symbolism | Routing | Representation |
|---|---|---|---|
| **Shiva** | Consciousness / Vowels | Left Branch | `.` (Dot) |
| **Shakti** | Energy / Consonants | Right Branch | `-` (Dash) |

## Encoding Rules

- Independent vowels (`अ आ इ ई ...`) and vowel modifiers (*matras*) are preferentially routed toward **Shiva paths**.
- Consonants (`क ख ग घ ...`) are preferentially routed toward **Shakti paths**.
- The generated tree remains:
  - Prefix-free
  - Frequency-optimized
  - Deterministic
  - Decodable

The result is a mathematically compressed symbolic representation of Sanskrit phonetics.

---

# 📊 Corpus & Dataset

The frequency model is built using a large-scale textual corpus extracted from structured JSON datasets containing:

- Rigveda
- Yajurveda
- Atharvaveda
- Srimad Bhagavad Gita
- Valmiki Ramayana
- Ramcharitmanas
- Mahabharata

The system parses and aggregates over **100,000 verses** written in Devanagari.

> To keep the repository lightweight, the original JSON corpus is omitted.
> A smaller `sample_corpus.txt` is included for testing and experimentation.

---

# ⚙️ Core Features

- UTF-8 Devanagari parsing
- Character frequency analysis
- Custom constrained Huffman Tree construction
- Prefix-free Sanskrit Morse generation
- Bidirectional translation:
  - Sanskrit → Shiva-Shakti Morse
  - Shiva-Shakti Morse → Sanskrit
- DOT/SVG tree visualization support
- O(1) Unicode hash mapping
- O(n log n) Min-Heap optimization

---

# 🛠️ Tech Stack

| Technology | Purpose |
|---|---|
| **Node.js** | Recursive JSON extraction & preprocessing |
| **C++** | Huffman engine, UTF-8 parsing, encoding/decoding |
| **Graphviz** | Tree visualization generation |

---

# 📂 Project Structure

```text
.
├── translator.cpp
├── shiva_shakti_tree.cpp
├── sample_corpus.txt
├── shiva_shakti_codes.txt
├── shiva_shakti_tree.dot
└── README.md
````

---

# 🚀 How to Run

## 1️⃣ Compile the Translator

Encode or decode Devanagari text using the generated Shiva-Shakti Morse system.

```bash
g++ translator.cpp -o translator
./translator
```

---

## 2️⃣ Build the Huffman Tree

Generate the frequency table, optimized tree, and encoding dictionary.

```bash
g++ shiva_shakti_tree.cpp -o shiva_tree -O3
./shiva_tree
```

### Generated Outputs

| File                     | Purpose                      |
| ------------------------ | ---------------------------- |
| `shiva_shakti_codes.txt` | Character → Morse dictionary |
| `shiva_shakti_tree.dot`  | Graphviz tree structure      |

---

## 3️⃣ Visualize the Language Hierarchy

Paste the contents of:

```text
shiva_shakti_tree.dot
```

into a Graphviz renderer such as WebGraphviz to visualize the Shiva-Shakti hierarchy.

---

# 📝 Example Encoding

The algorithm assigns shorter codes to structurally frequent symbols.

Example:

```text
य    : ..---
श    : .--..-
यश   : ..--- .--..-
```

Interestingly, the **Halant (्)** often receives one of the shortest encodings because of its extremely high structural frequency in Sanskrit word formation.

---

# 🧪 Algorithmic Insight

This project combines:

* Huffman Coding
* Unicode Processing
* Information Theory
* Sanskrit Phonetics
* Symbolic Linguistics

The tree is not merely statistical — it embeds a directional semantic constraint inspired by the Shiva–Shakti duality.

---

# 🔮 Future Possibilities

Potential extensions include:

* Sanskrit speech compression
* Phonetic entropy analysis
* AI tokenization research
* Sanskrit-aware NLP pipelines
* Devanagari symbolic transmission systems
* Real-time chanting compression

---

# 🙏 Acknowledgments

The Sanskrit and Awadhi textual datasets were sourced from the **DharmicData** repository.

This project uses their compiled datasets under the **Open Database License (ODbL)**.

Special respect to the preservation efforts surrounding Bharatiya linguistic and scriptural heritage.

---

# 📜 License

This project is intended for educational, research, and experimental purposes.

Please respect the licenses associ
