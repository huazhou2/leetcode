class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[]
        def dfs(nums,path):
            if not nums:
                res.append(path)
                return
            dfs(nums[1:],path)
            dfs(nums[1:],path+[nums[0]])
        dfs(nums,[])
        return res

a=Solution()

print(a.subsets([1,2,3]))



