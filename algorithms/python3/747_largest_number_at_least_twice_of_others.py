from typing import List
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if (len(nums)<=1):
            return 0
        max_num=nums[0]
        ind=0
        for i in range(1,len(nums)):
            if max_num< nums[i]:
                max_num=nums[i]
                ind=i
        cnt=0
        for i in range(len(nums)):
            if max_num<2*nums[i]:
                cnt+=1
                if cnt>=2:
                    return -1
        return ind


a1=Solution()

print(a1.dominantIndex([3,6,1,0]))
