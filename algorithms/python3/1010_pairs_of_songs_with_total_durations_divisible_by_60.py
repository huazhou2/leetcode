class Solution(object):
    def numPairsDivisibleBy60(self, time):
        """
        :type time: List[int]
        :rtype: int
        """
        nums=[x % 60 for x in time]
        cnts=collections.Counter(nums)

        res=0
        for i in range(1,30):
            res+=cnts[i]*cnts[60-i]
        res+=cnts[0]*(cnts[0]-1)/2
        res+=cnts[30]*(cnts[30]-1)/2
        return res



a=Solution()

print(a.numPairsDivisibleBy60([30,20,150,100,40]))