from typing import List
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res=[[]]
        def dfs(nums,cur,res):
            for i,n in enumerate(nums):
                if i>0 and n==nums[i-1]:
                    continue
                res+=[cur+[n]]
                dfs(nums[i+1:],cur+[n],res)
        dfs(sorted(nums),[],res)
        return res


a=Solution()

nums=[1,2,2]
print(a.subsetsWithDup(nums))