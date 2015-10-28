class Solution {
public:
    bool isHappy(int n) {
    int sum=0, count=0;
    while (sum !=1)
        {
        sum=0;
        while (n>0)
            {
            sum+=(n%10)*(n%10);
            n=n/10;
            }
            n=sum;
            count++;
            if (count>1000)
            return 0;
            
        }
        return 1;
        
    }
};
