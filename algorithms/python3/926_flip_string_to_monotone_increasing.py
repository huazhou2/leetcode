class Solution(object):
    def minFlipsMonoIncr(self, S):
        """
        :type S: str
        :rtype: int
        """
        n=len(S)
        left,right=[0]*n,[0]*n
        cur=0
        for i in range(n):
            if S[i]=='1':
                cur+=1
            left[i]=cur

        cur=0
        for i in range(n-1,-1,-1):
            if S[i]=='0':
                cur+=1
            right[i]=cur

        ans=min(left[-1],right[0])
        for i in range(n-1):
            ans=min(ans,left[i]+right[i+1])
        return ans

a=Solution()

print(a.minFlipsMonoIncr( "00110"))


