class Solution {
public:
    int countDigitOne(int n) {
        int total=0;
        for (long long i=1;i<=n;i*=10) {
            int before=n/i;
            int after=n%i;
            int remain=before%10;
            if (remain>=2 && remain<=9)
                total=total+(before/10+1)*i;
            else
                total=total+before/10*i+(remain==1)*(after+1);
        }
        return total;
        }
};

