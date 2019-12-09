class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        '''dynamic programming'''
        res=triangle[-1].copy()
        for i in range(len(triangle)-2,-1,-1):
            for j in range(len(triangle[i])):
                res[j]=min(res[j],res[j+1])+triangle[i][j]
        return res[0]

a=Solution()

nums=[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

print(a.minimumTotal(nums))

