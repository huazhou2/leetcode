class Solution(object):
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        flag=0
        for i in range(1,len(A)):
            if (A[i]>A[i-1]):
                if not flag:
                    flag=1
                elif flag==-1:
                    return False
            elif (A[i]<A[i-1]):
                if not flag:
                    flag=-1
                elif flag==1:
                    return False
        return True



a=Solution()

print(a.isMonotonic([2,2,2,1,4,5]))
