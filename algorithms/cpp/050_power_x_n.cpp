class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        if (n==1) return x;
        
        double res=n>0?myPow(x,n/2):1/myPow(x,-n/2);
        if (n%2) return n>0?(res*res*x):(res*res/x);
        else return (res*res);
        
    }
};
