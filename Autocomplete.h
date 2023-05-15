#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <vector>
#include <string>
using namespace std;

class AutoTrieNode {
public:
    vector<AutoTrieNode*> children;
    bool isEndOfWord;

    AutoTrieNode();
};

class Autocomplete {
private:
    AutoTrieNode* root;

public:
    Autocomplete();
    void insert(string word);
    void getAllSuggestions(AutoTrieNode* node, string prefix, vector<string>& suggestions);
    vector<string> getSuggestions(string partialWord);
};

#endif  
