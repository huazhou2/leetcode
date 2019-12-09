class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt=0
        nums=sorted(nums)
        for i in range(len(nums)-2):
            for j in range(i+1,len(nums)-1):
                vec2=nums[i]+nums[j]
                start=j+1
                end=len(nums)-1
                while (start<=end):
                    mid=(start+end)//2
                    if nums[mid]>=vec2:
                        end=mid-1
                    else:
                        start=mid+1
                cnt=cnt+start-j-1
        return cnt

a1=Solution()

print(a1.triangleNumber([2,2,3,4]))

