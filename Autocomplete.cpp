#include "Autocomplete.h"
using namespace std;

AutoTrieNode::AutoTrieNode() : children(26, nullptr), isEndOfWord(false) {}

Autocomplete::Autocomplete() {
    root = new AutoTrieNode();
}

void Autocomplete::insert(string word) {
    AutoTrieNode* curr = root;

    for (char c : word) {
        int index = c - 'a';

        if (curr -> children[index] == nullptr) {
            curr -> children[index] = new AutoTrieNode();
        }

        curr = curr -> children[index];
    }

    curr -> isEndOfWord = true;
}

void Autocomplete::getAllSuggestions(AutoTrieNode* node, string prefix, vector<string>& suggestions) {
    if (node == nullptr) {
        return;
    }

    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            char c = 'a' + i;
            getAllSuggestions(node->children[i], prefix + c, suggestions);
        }
    }
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
    vector<string> suggestions;
    AutoTrieNode* curr = root;

    for (char c : partialWord) {
        int index = c - 'a';

        if (curr -> children[index] == nullptr) {
            return suggestions;
        }

        curr = curr -> children[index];
    }

    getAllSuggestions(curr, partialWord, suggestions);
    return suggestions;
}
