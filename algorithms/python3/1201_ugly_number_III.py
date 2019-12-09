class Solution(object):
    def nthUglyNumber(self, n, a, b, c):
        """
        :type n: int
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        def gcd(x,y):
            while y:
                x,y=y,x%y
            return x
        def lcm(x,y):
            return x*y/gcd(x,y)
        def count(n,a,b,c):
            ans=n//a+n//b+n//c
            ans-=n//lcm(a,b)+n//lcm(a,c)+n//lcm(b,c)
            ans+=n//(lcm(lcm(a,b),c))
            return ans


        left,right=1,2*10**9
        while left<=right:
            mid=(left+right)//2
            if count(mid,a,b,c)<n:
                left=mid+1
            else:
                right=mid-1
        return left





a=Solution()

print(a.nthUglyNumber(4,2,3,4))

