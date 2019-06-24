class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        if (n==1) return true;
        int num=n-1;
        while(num) {
            if ((num & 1) == 0 ) return false;
            num=num>>1;
        }
        return true;
        }
};
