class Solution:
    def threeSumClosest(self, nums, target):
        if len(nums)<3:
            return sum(nums)
        nums.sort()
        res_sum=sum(nums[:3])
        res=abs(res_sum-target)
        i=0
        while i< len(nums)-2:
            if i>0 and nums[i]==nums[i-1]:
                continue
            j=i+1
            k=len(nums)-1
            while j<k:
                tot=nums[i]+nums[j]+nums[k]
                diff=abs(tot-target)
                if diff<res:
                    res=diff
                    res_sum=tot
                if tot>target:
                    k-=1
                    while k>0 and nums[k]==nums[k-1]:
                        k=k-1
                elif tot<target:
                    j+=1
                    while j<k and nums[j]==nums[j+1]:
                        j+=1
                else:
                    return target
            i+=1
        return res_sum


nums=[-1,2,1,-4]
a=Solution()

print(a.threeSumClosest(nums,1))







