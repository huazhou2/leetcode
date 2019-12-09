class Solution(object):
    def minEatingSpeed(self, piles, H):
        """
        :type piles: List[int]
        :type H: int
        :rtype: int
        """
        left,right=1,max(piles)
        n=len(piles)

        while left<=right:
            cnt=0
            mid=(left+right)//2
            for i in range(n):
                cnt+=-(-piles[i]//mid)
            if cnt<=H:
                right=mid-1
            else:
                left=mid+1
        return left

a=Solution()

print(a.minEatingSpeed([312884470],968709470))