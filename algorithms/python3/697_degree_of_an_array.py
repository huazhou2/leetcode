class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left,right,count={},{},{}
        for i,x in enumerate(nums):
            if x not in left:
                left[x]=i
            right[x]=i
            count[x]=count.get(x,0)+1
        rank=max(count.values())

        ans=len(nums)
        for key in count.keys():
            if count[key]==rank:
                ans=min(ans,right[key]-left[key]+1)
        return ans

a=Solution()

print(a.findShortestSubArray([1,2,2,3,1]))
print(a.findShortestSubArray([1,2,2,3,1,4,2]))

