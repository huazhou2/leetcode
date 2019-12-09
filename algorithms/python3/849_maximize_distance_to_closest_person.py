class Solution(object):
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        start=0
        maxl=0
        for i in range(len(seats)):
            if seats[i]:
                if start==0:
                    maxl=max(maxl,i-start)
                    start=i+1
                else:
                    maxl=max(maxl,(i-start+1)//2)
                    start=i+1
            elif i==len(seats)-1:
                maxl = max(maxl, i - start+1)
        return maxl

s=Solution()

print(s.maxDistToClosest([1,0,0,0,1,0,1]))
print(s.maxDistToClosest([1,0,0,0]))
