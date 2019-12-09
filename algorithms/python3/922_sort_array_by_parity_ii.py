class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        n=len(A)
        start,end=0,1
        while start<n and end<n:
            while start<n and A[start] % 2==0:
                start+=2
            while end<n and A[end] % 2 ==1:
                end+=2
            if start<n and end<n:
                A[start],A[end]=A[end],A[start]
        return A
    def sortArrayByParityII2(self,A):
        n=len(A)
        j=1
        for i in range(0,n,2):
            if A[i] % 2:
                while A[j] % 2 ==1:
                    j+=2
                A[i],A[j]=A[j],A[i]
        return A



a=Solution()

print(a.sortArrayByParityII2([4,2,5,7]))