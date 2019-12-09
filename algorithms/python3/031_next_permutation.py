class Solution:
    def nextPermutation(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1,0,-1):
            if nums[i]>nums[i-1]:
                ind=i
                while ind<len(nums):
                    if nums[ind]>nums[i-1]:
                        ind+=1
                    else:
                        break
                ind-=1
                nums[i-1],nums[ind]=nums[ind],nums[i-1]
                for j in range(i,i+(len(nums)-i)//2):
                    nums[j],nums[len(nums)-(j-i)-1]=nums[len(nums)-(j-i)-1],nums[j]
                return
        nums.sort()


nums=[1,2,3]

a=Solution()

a.nextPermutation(nums)

