class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        ##binary search
        left,right=max(nums),sum(nums)

        while left <= right:
            cnt=1
            sumt=0
            mid=(left+right)//2
            for i in range(len(nums)):
                if sumt+nums[i]>mid:
                    cnt+=1
                    sumt=nums[i]
                else:
                    sumt+=nums[i]
            if cnt<=m:
                right=mid-1
            else:
                left=mid+1
        return left
    ###dynamic programming
    def splitArray2(self, nums, m):
        sums=[0]
        for x in nums:
            sums.append(sums[-1]+x)

        n=len(nums)
        res=[[sum(nums)]*(m+1) for _ in range(n+1)]
        res[0][0]=0

        for i in range(1,n+1):
            for j in range(1,m+1):
                for k in range(i):
                    res[i][j]=min(res[i][j],max(res[k][j-1],sums[i]-sums[k]))
        return res[n][m]




a=Solution()

print(a.splitArray2([1,2147483647],2))


