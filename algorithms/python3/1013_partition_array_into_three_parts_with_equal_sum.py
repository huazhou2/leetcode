class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        sumt=sum(A)

        if sumt % 3:
            return False
        sumt=sumt//3

        cur=0
        cnt=0
        for i in range(len(A)):
            cur+=A[i]
            if cur==sumt:
                cur=0
                cnt+=1
        return cnt==3

a=Solution()

print(a.canThreePartsEqualSum([0,2,1,-6,6,7,9,-1,2,0,1]))

