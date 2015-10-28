class TrieNode {
public:

    TrieNode(char a=0): p(a),exist(false) { fillnull(child);}
    void fillnull(TrieNode** array) {
        for (int i=0;i<26;i++) {
            array[i]=NULL;
        }
    }
    char p;
    bool exist;
    TrieNode* child[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }


    void insert(string word) {
        TrieNode* cur=root;
        if (!word.empty()) {
            for (int i=0;i<word.size();i++) {
                if (!cur->child[word[i]-'a']) 
                    cur->child[word[i]-'a']=new TrieNode(word[i]);
                cur=cur->child[word[i]-'a'];
            }
        cur->exist=true;
        }
    }


    bool search(string word) {
        if (word.empty()) return false;
        TrieNode* cur=root;
        for (int i=0;i<word.size();i++) {
            if (cur->child[word[i]-'a']) cur=cur->child[word[i]-'a'];
            else return false;
        }
        if (cur->exist==true) return true;
        else return false;
    }


    bool startsWith(string prefix) {
        if (prefix.empty()) return false;
        TrieNode* cur=root;
        for (int i=0;i<prefix.size();i++) {
            if (cur->child[prefix[i]-'a']) cur=cur->child[prefix[i]-'a'];
            else return false;
        }
        return true;
        }
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// // Trie trie;
// // trie.insert("somestring");
// // trie.search("key");
