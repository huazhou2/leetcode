class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        cnt=0
        for i in range(len(nums)-1):
            if nums[i]>nums[i+1]:
                cnt+=1
                if i-1>=0 and nums[i-1]>nums[i+1]:
                    nums[i+1]=nums[i]
                else:
                    nums[i]=nums[i+1]
            if cnt>1:
                return False
        return True
