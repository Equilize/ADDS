#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode();
};

class Autocomplete {
private:
    TrieNode* root;

public:
    Autocomplete();
    void insert(string word);
    void getAllSuggestions(TrieNode* node, string prefix, vector<string>& suggestions);
    vector<string> getSuggestions(string partialWord);
};

#endif  
