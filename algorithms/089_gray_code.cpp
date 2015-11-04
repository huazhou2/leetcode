class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n<0) return result;
        result.push_back(0);
        for (int i=0;i<n;i++) {
            int num=pow(2,i);
            for (int j=0;j<num;j++) 
                result.push_back((1<<i)+result[num-j-1]);
            }
        return result;
        }
};
