class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s=sum(nums)
        cursum=0
        for i,x in enumerate(nums):
            if cursum==s-x-cursum:
                return i
            cursum += x
        return -1


a=Solution()
print(a.pivotIndex([-1,-1,-1,-1,-1,-1]))

