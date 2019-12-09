class Solution:
    def search(self, nums, target):

        if (len(nums) == 0):
            return -1
        else:
            return self.bins(nums, 0, len(nums) - 1, target)

    def bins(self, nums, start, end, target):
        if start > end:
            return -1
        mid = (start + end) // 2
        if target == nums[mid]:
            return (start + end) // 2
        if nums[mid] >= nums[start]:
            if target < nums[mid] and target >= nums[start]:
                return self.bins(nums, start, mid - 1, target)
            else:
                return self.bins(nums, mid + 1, end, target)
        else:
            if target > nums[mid] and target <= nums[end]:
                return self.bins(nums, mid + 1, end, target)
            else:
                return self.bins(nums, start, mid - 1, target)

a=Solution()

nums=[4,5,6,7,0,1,2]

print(a.search(nums,0))
