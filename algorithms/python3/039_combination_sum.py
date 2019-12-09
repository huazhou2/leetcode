class Solution:
    def combinationSum(self, candidates, target):
        candidates.sort()
        res=[]

        def dfs(target,start,path):
            if target==0:
                res.append(path)
                return
            if target<0:
                return
            for i in range(start,len(candidates)):
                if candidates[i]>target:
                    break
                dfs(target-candidates[i],i,path+[candidates[i]])
        dfs(target,0,[])
        return res


a=Solution()
nums=[2,3,6,7]


print(a.combinationSum(nums,7))

