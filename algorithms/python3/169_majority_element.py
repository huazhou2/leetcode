class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hash=dict()
        for num in nums:
            if num in hash:
                hash[num]+=1
            else:
                hash[num]=1
            if hash[num]>len(nums)/2:
                return num

a=Solution()

nums=[3,2,3]

print(a.majorityElement(nums))
