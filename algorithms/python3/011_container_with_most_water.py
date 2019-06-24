class Solution:
    def maxArea(self, height):
        i,j=0,len(height)-1
        maxarea=(j-i)*min(height[i],height[j])
        while i<j:
            if height[i]>height[j]:
                j=j-1
            else:
                i=i+1
            maxarea=max(maxarea,(j-i)*min(height[i],height[j]))
        return maxarea


res=Solution()

print(res.maxArea([1,8,6,2,5,4,8,3,7]))

