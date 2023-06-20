class TrieNode {
   public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (auto& x : child) {
            x = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;

   public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* parent = root;
        for (auto& c : word) {
            int idx = c - 'a';
            if (!parent->child[idx]) parent->child[idx] = new TrieNode();
            parent = parent->child[idx];
        }
        parent->isEnd = true;
    }

    bool searchPrefix(string word) {
        TrieNode* parent = root;
        for (auto& c : word) {
            int idx = c - 'a';
            if (!parent->child[idx]) return false;
            parent = parent->child[idx];
        }

        return true;
    }

    bool search(string word) {
        TrieNode* parent = root;
        for (auto& c : word) {
            int idx = c - 'a';
            if (!parent->child[idx]) return false;
            parent = parent->child[idx];
        }

        return parent->isEnd;
    }

    bool startsWith(string prefix) {
        return searchPrefix(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */