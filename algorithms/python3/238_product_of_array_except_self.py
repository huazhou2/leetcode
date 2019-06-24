class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res=[1]*len(nums)
        res[0]=1
        for i in range(len(nums)-1):
            res[i+1]=res[i]*nums[i]
        cur=1
        for i in range(len(nums)-1,-1,-1):
            res[i]=cur*res[i]
            cur=cur*nums[i]

        return res

a=Solution()

nums=[1,2,3,4]
print(a.productExceptSelf(nums))
