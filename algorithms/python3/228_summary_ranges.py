class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        res=[]
        low,high=nums[0],nums[0]
        for i in range(1,len(nums)):
            if nums[i]-nums[i-1]>1:
                if low==high:
                    res.append(str(low))
                else:
                    res.append(str(low)+'->'+str(high))
                low=high=nums[i]
            else:
                high=nums[i]
        if low==high:
           res.append(str(low))
        else:
           res.append(str(low)+'->'+str(high))
        return res

a=Solution()

nums=[0,1,2,4,5,7]
print(a.summaryRanges(nums))


