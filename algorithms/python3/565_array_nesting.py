class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=1
        for i in range(len(nums)):
            cnt=1
            while nums[i]!=nums[nums[i]]:
                cur=nums[i]
                nums[i],nums[cur]=nums[cur],nums[i]
                cnt+=1
            res=max(res,cnt)
        return res

a=Solution()

print(a.arrayNesting([5,4,0,3,1,6,2]))