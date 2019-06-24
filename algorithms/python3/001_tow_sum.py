class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap=dict()
        for i,num in enumerate(nums):
            if target-num in hashmap:
                return([hashmap[target-num],i])
            hashmap[num]=i



res=Solution()

print(res.twoSum([2,7,11,15],9))