class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        def twoSumSmaller(nums,start,end,target):
            sum=0
            while start<end:
                if nums[start]+nums[end]<target:
                    sum+=end-start
                    start+=1
                else:
                    end-=1
            return sum
        sum=0
        nums.sort()
        for i in range(len(nums)-2):
            sum+=twoSumSmaller(nums,i+1,len(nums)-1,target-nums[i])
        return sum

a=Solution()

nums=[-2,3,1,0]

print(a.threeSumSmaller(nums,2))