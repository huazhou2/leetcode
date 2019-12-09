class Solution(object):
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        n=len(A)
        start=1
        while start<n and A[start]>A[start-1]:
            start+=1
        if start==n or start==1:
            return False
        start-=1
        while start<n-1 and A[start]>A[start+1]:
            start+=1
        return start>0 and n>=3 and start==n-1


a=Solution()


print(a.validMountainArray([1,3,2]))

