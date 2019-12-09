from typing import List
class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        def count(B):
            ans = cur = 0
            for x in A:
                if x <=B:
                    cur+=1
                else:
                    cur=0
                ans+=cur
            return ans
        return count(R)-count(L-1)


a=Solution()
num=[2,1,4,3]
print(a.numSubarrayBoundedMax(num,2,3))