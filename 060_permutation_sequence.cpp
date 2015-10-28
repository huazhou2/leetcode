class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> pos(n,k-1);
        int cur=k-1;
        int dividend=1;
        vector<int> pool;
        for (int i=0;i<n;i++) {
            pool.push_back(i+1);
            for (int j=2;j<=n-i-1;j++)
                {pos[i]=pos[i]/j;
                if (pos[i]==0) break;}
        if (pos[i]!=0) pos[i]%=(n-i);
        }
        string result;
        vector<int>::iterator it=pool.begin();
        for (int i=0;i<n;i++) {
            result+=static_cast<char> (*(it+pos[i])+'0');
            pool.erase(it+pos[i]);
        }
        return result;
        }
};
