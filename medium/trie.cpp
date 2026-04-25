#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    bool is_end = false;
    TrieNode() : children(26) {};
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        this->root = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* ptr = this->root;
        for (char c : word) {
            int c_int = (int)(c - 'a');
            if((ptr->children)[c_int] == nullptr) {
                (ptr->children)[c_int] = new TrieNode();
            }
            ptr = (ptr->children)[c_int];
        }
        ptr->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* ptr = this->root;
        for (char c : word) {
            int c_int = (int)(c - 'a');
            if((ptr->children)[c_int] == nullptr) {
                return false;
            }
            ptr = (ptr->children)[c_int];
        }
        if (ptr->is_end) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* ptr = this->root;
        for (char c : prefix) {
            int c_int = (int)(c - 'a');
            if((ptr->children)[c_int] == nullptr) {
                return false;
            }
            ptr = (ptr->children)[c_int];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
