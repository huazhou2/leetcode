class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        def maxHist(nums):
            maxarea=0
            stack=[-1]
            for i in range(len(nums)):
                while stack[-1]!=-1 and nums[i]<=nums[stack[-1]]:
                    top=stack.pop()
                    maxarea=max(maxarea,(i-stack[-1]-1)*nums[top])
                stack.append(i)
            while len(stack)>1:
                top=stack.pop()
                maxarea=max(maxarea,(len(nums)-stack[-1]-1)*nums[top])
            return maxarea
        if not matrix or not matrix[0]:
            return 0
        maxarea=0
        curhist=[0]*len(matrix[0])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                curhist[j]=curhist[j]+1 if matrix[i][j]=='1' else 0
            maxarea=max(maxarea,maxHist(curhist))
        return maxarea

a=Solution()

matrix=[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]

print(a.maximalRectangle(matrix))
