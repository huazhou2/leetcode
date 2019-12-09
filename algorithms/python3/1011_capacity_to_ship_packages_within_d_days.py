class Solution(object):
    def shipWithinDays(self, weights, D):
        """
        :type weights: List[int]
        :type D: int
        :rtype: int
        """
        #doing binary search
        left,right=max(weights),sum(weights)
        n=len(weights)

        while left<=right:
            sumt=0
            cnt=1
            mid=(left+right)//2
            for i in range(n):
                if sumt+weights[i]>mid:
                    cnt+=1
                    sumt=weights[i]
                else:
                    sumt+=weights[i]
            if cnt<=D:
                right=mid-1
            else:
                left=mid+1
        return left


a=Solution()

print(a.shipWithinDays([1,2,3,4,5,6,7,8,9,10],5))
