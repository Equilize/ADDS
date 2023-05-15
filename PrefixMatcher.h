#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <string>

const int ALPHABET_SIZE = 2; 

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    int routerNumber;
    bool isEndOfAddress;

    TrieNode();
};

class PrefixMatcher {
private:
    TrieNode* root;

public:
    PrefixMatcher();

    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);
};

#endif
