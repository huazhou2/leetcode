class Solution(object):
    def prefixesDivBy5(self, A):
        """
        :type A: List[int]
        :rtype: List[bool]
        """
        res=[]
        cur=0
        for i in range(len(A)):
            cur=(cur*2+A[i])%5
            if cur ==0:
                res.append(True)
            else:
                res.append(False)
        return res


a=Solution()

print(a.prefixesDivBy5([1,1,1,0,1]))
