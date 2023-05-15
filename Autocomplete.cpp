#include "Autocomplete.h"
using namespace std;

TrieNode::TrieNode() : children(26, nullptr), isEndOfWord(false) {}

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::insert(string word) {
    TrieNode* curr = root;

    for (char c : word) {
        int index = c - 'a';

        if (curr -> children[index] == nullptr) {
            curr -> children[index] = new TrieNode();
        }

        curr = curr -> children[index];
    }

    curr -> isEndOfWord = true;
}

void Autocomplete::getAllSuggestions(TrieNode* node, string prefix, vector<string>& suggestions) {
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
    TrieNode* curr = root;

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
