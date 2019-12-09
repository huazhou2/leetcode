class Solution:
    def jump(self, nums):
        if (len(nums)<=1):
            return 0;
        start,cur,end=-1,0,0
        while start !=end:
            if end>=len(nums)-1:
                return cur
            temp=end
            cur+=1

            for i in range(temp,start,-1):
                if i+nums[i]>end:
                    end=i+nums[i]
            start=temp
        return cur

a=Solution()
print(a.jump([2,3,1,1,4]))
        