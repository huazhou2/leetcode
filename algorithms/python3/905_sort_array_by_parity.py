class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        start,end=0,len(A)-1
        while start<end:
            while A[start] % 2 ==0 and start<end:
                start+=1
            while A[end] % 2==1 and end>=start:
                end-=1
            if start<end:
                A[start],A[end]=A[end],A[start]
                start+=1
                end-=1

        return A


a=Solution()

A=[3,1,2,4]
print(a.sortArrayByParity(A))



