class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:

        def dfs(start,k,target,path):
            if len(path)==k and target==0:
                res.append(path)
            else:
                for i in range(start,10):
                    if target<i:
                        break
                    else:
                        dfs(i+1,k,target-i,path+[i])

        res=[]
        dfs(1,k,n,[])
        return res

a=Solution()

print(a.combinationSum3(3,9))

