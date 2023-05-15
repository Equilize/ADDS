#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <string>

const int ALPHABET_SIZE = 2; 

class PrefixTrieNode {
public:
    PrefixTrieNode* children[ALPHABET_SIZE];
    int routerNumber;
    bool isEndOfAddress;

    PrefixTrieNode();
};

class PrefixMatcher {
private:
    PrefixTrieNode* root;

public:
    PrefixMatcher();

    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);
};

#endif
