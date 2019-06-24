#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if (words.empty()) return result;
        dfs(words,0,maxWidth,result);
        return result;
    }
    void dfs(vector<string>& words, int start, int maxWidth, vector<string>& result) {
        int length=words[start].size();
        int end=start+1;
        for (;end<words.size();end++) {
            int temp=length+words[end].size()+1;
            if (temp<=maxWidth) length=temp;
            else  break;}
        if (end==words.size()) {
            string path("");
            for (int i=start;i<end;i++) {
                path+=words[i]+" ";
            }
            path.erase(path.size()-1);
            for (int i=length;i<=maxWidth;i++) 
                path+=" ";
            result.push_back(path);
            return;
        }
        else {
            result.push_back(process(words,start,end-1,length, maxWidth));
        }
        dfs(words,end,maxWidth,result);
        }
        string process(vector<string>& words, int start, int end, int length, int maxWidth) {
            string path="";
            if (start==end) {path+=words[start];
                            path.append(maxWidth-length, ' ');}
            else {
                int size=end-start;
                int space=(maxWidth-length)/size+1;
                int extra=(maxWidth-length)%size;
                for (int i=start;i<end;i++) {
                    path+=words[i];
                    if (i-start<extra) path.append(space+1, ' ');
                    else path.append(space,' ');
                }
		path+=words[end];
                }
            return path;
            }
};
	void print(vector<string>& result) {
		if (!result.empty()) {
		for (int i=0;i<result.size();i++)
			cout<<result[i]<<endl;
		}}

int main() {
	string a[]={"Birnbaum", "also", "led", "the", "Incident", "Command", "Team", "during", "Hurricane", "Sandy.", "Many", "of", "you", "worked", "closely", "that", "night", "with", "him", "and", "others,", "ensuring", "that", "all", "NYU", "Langone", "patients", "were", "safely", "discharged", "or", "transferred", "to", "other", "institutions.", "I", "vividly", "recall", "the", "morning", "following", "the", "storm", "when", "Dr.", "Birnbaum", "addressed", "the", "staff", "after", "15", "grueling", "hours,", "clearly", "moved", "and", "inspired", "by", "the", "massive", "effort.", "He", "said,", "Everyone", "here", "is", "a", "hero.", "Thank", "you,", "thank", "you,", "thank", "you.”", "But", "no", "one", "was", "more", "of", "a", "hero", "that", "night", "than", "Dr.", "Birnbaum"};
	vector<string> words(a,a+sizeof(a)/sizeof(string));
	Solution m;
	vector<string> result=m.fullJustify(words,26);
	print(result);
	}
