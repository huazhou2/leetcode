from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)<=2:
            return len(nums)
        res=1
        count=1
        cur=0
        for i in range(1,len(nums)):
            if count>=2:
                if nums[i]==nums[cur]:
                    continue
                else:
                    count=1
                    cur+=1
                    nums[cur]=nums[i]
                    res+=1
            else:
                if nums[i]==nums[cur]:
                    count+=1

                cur+=1
                nums[cur]=nums[i]
                res+=1
        return res

a=Solution()

nums=[1,1,1,2,2,3]

print(a.removeDuplicates(nums))