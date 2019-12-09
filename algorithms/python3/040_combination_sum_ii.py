class Solution:
    def combinationSum2(self, candidates, target):
        candidates.sort()
        res=[]
        def dfs(target,start,path):
            if target==0 and path not in res:
                res.append(path)
                return
            if target<0:
                return
            for i in range(start,len(candidates)):
                if candidates[i]>target:
                    break
                dfs(target-candidates[i],i+1,path+[candidates[i]])
        dfs(target,0,[])
        return res



a=Solution()

print(a.combinationSum2([10,1,2,7,6,1,5],8))
