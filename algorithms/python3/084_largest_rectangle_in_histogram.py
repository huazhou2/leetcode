
from typing import List
class Solution:
    def largestRectangleArea2(self, heights: List[int]) -> int:
        '''divide and conquer'''
        def helper(nums,start,end):
            if start>end:
                return 0
            min_height=float('inf')
            ind=start
            for i in range(start,end+1):
                if nums[i]<min_height:
                    min_height=nums[i]
                    ind=i
            return max(min_height*(end-start+1),helper(nums,start,ind-1),helper(nums,ind+1,end))
        return helper(heights,0,len(height)-1)
    def largestRectangleArea2(self, heights: List[int]) -> int:
        max_area=0
        stack=[-1]
        for i in range(len(heights)):
            while stack[-1] !=-1 and heights[i]<=heights[stack[-1]]:
                top=stack.pop()
                max_area=max(max_area,(i-stack[-1]-1)*heights[top])
            stack.append(i)
        while len(stack)>1:
            top=stack.pop()
            max_area=max(max_area,(len(heights)-stack[-1]-1)*heights[top])
        return max_area




a=Solution()

nums=[2,1,5,6,2,3]

print(a.largestRectangleArea(nums))
