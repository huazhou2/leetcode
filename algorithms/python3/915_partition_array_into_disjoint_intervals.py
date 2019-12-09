class Solution(object):
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n=len(A)
        maxleft=[None]*n
        minright=[None]*n
        m=A[0]
        for i in range(n):
            m=maxleft[i]=max(m,A[i])
        m=A[-1]
        for i in range(n-1,-1,-1):
            m=minright[i]=min(m,A[i])

        for i in range(n-1):
            if maxleft[i]<=minright[i+1]:
                    return i+1
        return n


a=Solution()

print(a.partitionDisjoint([5,0,3,8,6]))


