class Solution {
public:
    int mySqrt(int x) {
        if (x<=0)   return 0;
        int temp=x;
        int digit=0;
        while(temp) {
                temp=temp>>1;
                digit++;
        }
        
        for (int i=(x>>((digit+1)/2));i<=(x>>((digit-1)/2));i++)   {
            if (i*i<=x && ((i+1)*(i+1)>x || (i+1)*(i+1)<0))
                return i;
        }
        
    }
};
