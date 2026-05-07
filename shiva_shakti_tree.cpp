#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 1. Philosophical Classification
enum NodeType { SHIVA, SHAKTI, MIXED };

struct Node {
    string character;
    int freq;
    NodeType type;
    Node* left;
    Node* right;

    Node(string c, int f, NodeType t) : character(c), freq(f), type(t), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Vowels & Matras (Shiva/Consciousness)
unordered_set<string> shivaSet = {
    "अ", "आ", "इ", "ई", "उ", "ऊ", "ऋ", "ॠ", "ऌ", "ॡ", "ए", "ऐ", "ओ", "औ",
    "ा", "ि", "ी", "ु", "ू", "ृ", "ॄ", "े", "ै", "ो", "ौ", "ं", "ः", "ँ", "्", "ऽ"
};

NodeType classifyCharacter(const string& ch) {
    if (shivaSet.find(ch) != shivaSet.end()) return SHIVA;
    return SHAKTI; // Consonants (Shakti/Energy)
}

// 2. Output the Morse Codes
void writeCodes(Node* root, string code, ofstream& outFile) {
    if (!root) return;

    if (!root->left && !root->right) {
        outFile << root->character << " : " << code << "\n";
    }

    writeCodes(root->left, code + ".", outFile);
    writeCodes(root->right, code + "-", outFile);
}

// 3. Generate the Visual Graph (Insta-Reel style)
void writeDot(Node* root, ofstream& out, int& id) {
    if (!root) return;
    int currentId = id;
    
    if (root->left) {
        int leftId = ++id;
        out << "  node" << currentId << " -> node" << leftId << " [label=\".\"];\n";
        string label = (!root->left->left && !root->left->right) ? root->left->character : "O"; // 'O' for internal node
        out << "  node" << leftId << " [label=\"" << label << "\\n" << root->left->freq << "\" shape=" 
            << ((!root->left->left) ? "box color=lightblue" : "circle") << "];\n";
        writeDot(root->left, out, id);
    }
    if (root->right) {
        int rightId = ++id;
        out << "  node" << currentId << " -> node" << rightId << " [label=\"-\"];\n";
        string label = (!root->right->left && !root->right->right) ? root->right->character : "O";
        out << "  node" << rightId << " [label=\"" << label << "\\n" << root->right->freq << "\" shape=" 
            << ((!root->right->left) ? "box color=lightpink" : "circle") << "];\n";
        writeDot(root->right, out, id);
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Loading 101,352 verses into memory...\n";

    unordered_map<string, int> freqMap;
    ifstream file("master_devanagari_corpus.txt");
    string word;

    if (!file.is_open()) {
        cout << "Error: Could not open master_devanagari_corpus.txt!\n";
        return 1;
    }

    // --- THE STRICT DEVANAGARI UTF-8 PARSER ---
    while (file >> word) {
        for (size_t i = 0; i < word.length(); ) {
            int cplen = 1;
            unsigned char c = word[i];

            // Determine UTF-8 char length
            if ((c & 0xF8) == 0xF0) cplen = 4;
            else if ((c & 0xF0) == 0xE0) cplen = 3; 
            else if ((c & 0xE0) == 0xC0) cplen = 2;

            if (cplen == 3) {
                // Check if it specifically falls in the Devanagari Unicode Block (E0 A4 80 to E0 A5 BF)
                unsigned char b2 = word[i+1];
                if (c == 0xE0 && (b2 == 0xA4 || b2 == 0xA5)) {
                    unsigned char b3 = word[i+2];
                    
                    // Filter out Numbers (०-९) and Dandas (।, ॥)
                    bool isNumber = (b2 == 0xA5 && b3 >= 0xA6 && b3 <= 0xAF);
                    bool isDanda = (b2 == 0xA5 && (b3 == 0xA4 || b3 == 0xA5));
                    
                    if (!isNumber && !isDanda) {
                        string uchar = word.substr(i, 3);
                        freqMap[uchar]++;
                    }
                }
            }
            i += cplen;
        }
    }
    file.close();

    cout << "Filtered Data! Found exactly " << freqMap.size() << " core Devanagari characters/matras.\n";
    cout << "Building the Shiva-Shakti Tree...\n";

    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (auto pair : freqMap) {
        NodeType t = classifyCharacter(pair.first);
        minHeap.push(new Node(pair.first, pair.second, t));
    }

    // --- BUILD THE TREE ---
    while (minHeap.size() > 1) {
        Node* first = minHeap.top(); minHeap.pop();
        Node* second = minHeap.top(); minHeap.pop();

        Node* parent = new Node("INTERNAL", first->freq + second->freq, MIXED);

        // SHIVA (Vowels) go Left (Dot). SHAKTI (Consonants) go Right (Dash).
        if (first->type == SHIVA || second->type == SHAKTI) {
            parent->left = first;
            parent->right = second;
        } else {
            parent->left = second;
            parent->right = first;
        }

        minHeap.push(parent);
    }

    Node* root = minHeap.top();

    // --- OUTPUT 1: The Clean Morse Codes ---
    ofstream textOut("shiva_shakti_codes.txt");
    textOut << "--- SANSKRIT SHIVA-SHAKTI MORSE CODES ---\n";
    writeCodes(root, "", textOut);
    textOut.close();

    // --- OUTPUT 2: The Visual Graphviz File ---
    ofstream dotOut("shiva_shakti_tree.dot");
    dotOut << "digraph HuffmanTree {\n";
    dotOut << "  node [fontname=\"Arial\"];\n"; // Fallback font, Graphviz web renders Devangari natively
    int id = 0;
    dotOut << "  node0 [label=\"ROOT\\n" << root->freq << "\" shape=circle];\n";
    writeDot(root, dotOut, id);
    dotOut << "}\n";
    dotOut.close();

    cout << "Success!\n";
    cout << "1. Text codes saved to 'shiva_shakti_codes.txt'\n";
    cout << "2. Visual map saved to 'shiva_shakti_tree.dot'\n";

    return 0;
}