class Solution:
    def trap(self, height):
        if not height:
            return 0
        left_max=[None]*len(height)
        right_max=[None]*len(height)
        left_max[0]=height[0]
        right_max[len(height)-1]=height[-1]
        for i in range(1,len(height)):
            left_max[i]=max(height[i],left_max[i-1])
        for i in range(len(height)-2,-1,-1):
            right_max[i]=max(height[i],right_max[i+1])
        tot=0
        for i in range(len(height)):
            tot+=min(left_max[i],right_max[i])-height[i]
        return tot

a=Solution()


nums=[0,1,0,2,1,0,1,3,2,1,2,1]

a.trap(nums)