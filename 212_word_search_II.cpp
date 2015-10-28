class TrieNode {
    public:
    TrieNode(): value(0) { fillChild(child);
    }
    TrieNode* child[26];
    int value;
    private:
    void fillChild(TrieNode** child)  
    { 
        for (int i=0;i<26;i++) 
            child[i]=NULL;
    }
};
class Trie {
    public: 
    Trie(): count(0) { root=new TrieNode(); }

    void insert(string word) {
        if (!word.empty()) {
            TrieNode* cur=root;
            for (int i=0;i<word.size();i++) {
                int ind=word[i]-'a';
                if (!cur->child[ind]) cur->child[ind]=new TrieNode();
                cur=cur->child[ind];
            }
        count++;
        cur->value=count;
        }
    }

    bool exist_word(string word) {
        if (word.empty()) return false;
        TrieNode* cur=root;
        for (int i=0;i<word.size();i++) {
            int ind=word[i]-'a';
            if (!cur->child[ind]) return false;
            cur=cur->child[ind];
        }
        if (cur->value!=0) return true;
        else return false;
    }

    bool exist_prefix(string prefix) {
        if (prefix.empty()) return false;
        TrieNode* cur=root;
        for (int i=0;i<prefix.size();i++) {
            int ind=prefix[i]-'a';
            if (!cur->child[ind]) return false;
            cur=cur->child[ind];
        }
        return true;
    }
    private:
    TrieNode* root;
    int count;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty() || board[0].empty() || words.empty()) return result;
        Trie word_trie;
        string path="";
        unordered_set<string> temp;
        for (int i=0;i<words.size();i++) 
            word_trie.insert(words[i]);
        for (int i=0;i<board.size();i++) {
            for (int j=0;j<board[0].size();j++) 
                {
                vector<bool> visited(board.size()*board[0].size(),false);
                dfs(board,word_trie,visited,i,j, temp, path);
                }
        }
        std::copy(temp.begin(),temp.end(),std::back_inserter(result));
        return result;
        }
    void dfs(vector<vector<char> >& board, Trie& word_trie, vector<bool>& visited, int i, int j, unordered_set<string>& result, string& path) {
        if (!word_trie.exist_prefix(path+board[i][j])) return;
        else {
            path.insert(path.end(),board[i][j]);
            visited[i*board[0].size()+j]=true;
            if (word_trie.exist_word(path)) 
                result.insert(path);
            if (i<board.size()-1 && visited[(i+1)*board[0].size()+j]==false) dfs(board,word_trie,visited,i+1,j,result,path);
            if (i>0 && visited[(i-1)*board[0].size()+j]==false) dfs(board,word_trie,visited,i-1,j,result,path);
            if (j<board[0].size()-1 && visited[i*board[0].size()+j+1]==false) dfs(board,word_trie,visited,i, j+1, result, path);
            if (j>0 && visited[i*board[0].size()+j-1]==false) dfs(board,word_trie,visited,i,j-1,result,path);
            path.erase(path.end()-1);
            visited[i*board[0].size()+j]=false;
            return;
            }
    }
};


