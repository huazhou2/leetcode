class Solution(object):
    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        if len(nums)<7:
            return False
        for i in range(3,len(nums)-3):
            if nums[i]==0 and nums[i+1]==0:
                continue
            left=self.candiv(nums[:i])
            right=self.candiv(nums[i+1:])
            for l in left:
                if l in right:
                    return True
        return False
    def candiv(self,nums):
        total=sum(nums)
        res=set()
        sumup=nums[0]
        for i in range(1,len(nums)-1):
            if (total-nums[i])%2==0 and sumup==(total-nums[i])/2:
                res.add(sumup)
            sumup+=nums[i]
        return res

a=Solution()

print(a.splitArray([1,2,1,2,1,2,1]))