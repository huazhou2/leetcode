class Solution(object):
    def minmaxGasDist(self, stations, K):
        """
        :type stations: List[int]
        :type K: int
        :rtype: float
        """
        left,right=1e-6,stations[-1]
        n=len(stations)

        while right-left>1e-6:
            mid=(left+right)/2
            cnt=0
            for i in range(n-1):
                cnt+=-((stations[i]-stations[i+1])//mid )-1

            if cnt<=K:
                right=mid
            else:
                left=mid
        return left


a=Solution()

print(a.minmaxGasDist([1, 2, 3, 4, 5, 6, 7, 8, 9, 10],9))
