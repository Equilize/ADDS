#include "PrefixMatcher.h"
using namespace std;

TrieNode::TrieNode() : routerNumber(-1), isEndOfAddress(false) {
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        children[i] = nullptr;
}

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

void PrefixMatcher::insert(string address, int routerNumber) {
    TrieNode* curr = root;
    for (char c : address) {
        int index = c - '0'; 
        if (curr -> children[index] == nullptr)
            curr -> children[index] = new TrieNode();
        curr = curr -> children[index];
    }
    curr -> isEndOfAddress = true;
    curr -> routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(string networkAddress) {
    TrieNode* curr = root;
    int longestPrefix = 0;
    int selectedRouter = -1;

    for (char c : networkAddress) {
        int index = c - '0'; 
        if (curr -> children[index] == nullptr)
            break;

        curr = curr -> children[index];
        if (curr -> isEndOfAddress) {
            longestPrefix++;
            selectedRouter = curr -> routerNumber;
        }
    }

    return selectedRouter;
}
