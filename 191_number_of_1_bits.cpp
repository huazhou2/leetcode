class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n==0)
            return 0;
        int count=0;
        while(n>0){
            if (n%2) count++;
            n=n/2;
        }
        return count;
        }
};
