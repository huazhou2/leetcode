class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.emplace(endWord);
        deque<string> temp;
        temp.push_back(beginWord);
        int length=1;
        while(!temp.empty()) {
            int que_size=temp.size();
            length++;
            for (int i=0;i<que_size;i++) {
                string pop_str=temp.front();
                stack<string> erase_stack;
                temp.pop_front();
                for (auto it=wordDict.begin();it!=wordDict.end();it++) {
                    if (matchOne(pop_str,*it)) {
                        if (*it==endWord) return length;;
                        temp.push_back(*it);
                        erase_stack.push(*it);}
                    }
                while(!erase_stack.empty()) {
                    wordDict.erase(erase_stack.top());
                    erase_stack.pop();
                }
            }
        }
        return 0; 
    }
    
    bool matchOne(const string& word1, const string& word2) {
        if (word1.size()!= word2.size()) return false;
        int count=0;
        for (int i=0;i<word1.size();i++) {
            if (word1[i]!=word2[i]) count++;
            if (count>1) break;}
        return (count==1);
        }
};
