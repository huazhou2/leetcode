class Solution(object):
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        mid=0
        n=len(A)
        while mid<n and A[mid]<0:
            mid+=1
        left=mid-1
        right=mid
        res=[]
        while right<n and left>=0:
            if (A[right]>(-A[left])):
                res.append(A[left]**2)
                left-=1
            else:
                res.append(A[right]**2)
                right+=1
        if left<0:
            while right<n:
                res.append(A[right]**2)
                right+=1
        else:
            while left>=0:
                res.append(A[left]**2)
                left-=1
        return res

a=Solution()

print(a.sortedSquares([-4,-1,0,3,10]))
