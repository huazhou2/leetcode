class WordDictionary {
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        int size=word.size();
        if (data.find(size)!=data.end()) 
            data[size].push_back(word);
        else 
            data[size]=vector<string> (1,word);
        }
// Returns if the word is in the data structure. A word could
//     // contain the dot character '.' to represent any one letter.


    bool search(string word) {
        int size=word.size();
        unordered_map<int,vector<string> > ::iterator it=data.find(size);
        if (it==data.end()) return false;
        for (vector<string>::iterator it2=it->second.begin();it2!=it->second.end();it2++) {
            if (match(word,*it2)) return true;}
            return false;
        }
    bool match (string word1, string word2) {
        for (int i=0;i<word1.size();i++) 
            if (word1[i]=='.' ||word1[i]==word2[i]) continue;
            else return false;
        return true;
    }
private:
    unordered_map<int,vector<string> > data;
};

// Your WordDictionary object will be instantiated and called as such:
// // WordDictionary wordDictionary;
// // wordDictionary.addWord("word");
// // wordDictionary.search("pattern");
