class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        int count=1;
        while(n>0) {
            result+= n%2*pow(2,32-count);
            count++;
            n=n/2;
        }
        return result;
    }
};
