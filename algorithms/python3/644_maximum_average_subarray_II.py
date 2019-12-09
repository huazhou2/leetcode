from typing import List
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n=len(nums)
        prefix=[0]*(n+1)
        for i in range(n):
            prefix[i+1]=prefix[i]+nums[i]

        def isAveragePossible(x):
            min_No_x=float('inf')
            for i in range(n):
                if i+k==n+1:
                    return False
                min_No_x=min(min_No_x,prefix[i]-i*x)
                if prefix[i+k]-(i+k)*x>=min_No_x:
                    return True
            return False


        lo,hi=min(nums),max(nums)

        while hi-lo>=10**(-10):
            mi=(hi+lo)/2.0
            if isAveragePossible(mi):
                lo=mi
            else:
                hi=mi
        return lo


a=Solution()

print(a.findMaxAverage([1,12,-5,-6,50,3],4))