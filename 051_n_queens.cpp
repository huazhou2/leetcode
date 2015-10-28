class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int,int> > > result;
        vector<pair<int,int> > temp;
        solveNQ(n,0,temp,result);
        vector<vector<string> > final;
        
        if (!result.empty()) {
            for (int i=0;i<result.size();i++) {
                vector<string> temp;
                for (int j=0;j<result[i].size();j++) {
                    string s("");
                    for (int k=0;k<n;k++)
                        s+= (k==result[i][j].second? 'Q':'.');
                    temp.push_back(s);
                }
            final.push_back(temp);
            }
        }
        return final;
    }
    void solveNQ(int n, int deep, vector<pair<int,int> >& temp, vector<vector<pair<int, int> > >& result) {
        if (deep==n) { result.push_back(temp); return;} 
        for (int i=0;i<n;i++) {
            if (isCorrect(i,temp)) {
                temp.push_back(make_pair(deep,i));
                int newdeep=deep+1;
                solveNQ(n,newdeep,temp,result);
                temp.pop_back();
            }

        }
    }
    bool isCorrect(int col,vector<pair<int, int > > & result) {
        if (result.empty()) return true;
        int size=result.size();
        for (int i=0;i<result.size();i++) {
            int t1=result[i].first;
            int t2=result[i].second;
            bool correct= abs(size-t1)!=abs(col-t2) && col!=t2;
            if (!correct) return false;
        }
        return true;
    }
};
