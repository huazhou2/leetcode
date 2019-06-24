class Solution:
    def threeSum(self, nums):
        nums.sort()
        res=[]
        i=0
        while i < len(nums)-2:
            if nums[i]>0:
                break
            target=-nums[i]
            j=i+1
            k=len(nums)-1
            while j<k:
                if nums[j]+nums[k]==target:
                    res.append([nums[i],nums[j],nums[k]])
                    j=j+1
                    k=k-1
                    while j<k and nums[j]==nums[j-1]:
                        j=j+1
                    while j<k and nums[k]==nums[k+1]:
                        k=k-1
                elif nums[j]+nums[k]<target:
                    j=j+1
                elif nums[j]+nums[k]>target:
                    k=k-1
            while nums[i]==nums[i+1] and i<(len(nums)-2):
                i=i+1
            i+=1
        return res

a=Solution()

print(a.threeSum([-1,0,1,2,-1,-4]))



