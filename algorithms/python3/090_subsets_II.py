class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res=[[]]
        def dfs(ns,c,res):
            for i,n in enumerate(ns):
                if i>0 and n==ns[i-1]:
                    continue
                res+=[c+[n]]
                dfs(ns[i+1:],c+[n],res)
        dfs(sorted(nums),[],res)
        return res

a=Solution()

nums=[1,2,2]
print(a.subsetsWithDup(nums))