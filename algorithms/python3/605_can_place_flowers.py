class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        i=0
        cnt=0
        while i<len(flowerbed):

            if not flowerbed[i] and (i==0 or not flowerbed[i-1]) and (i==len(flowerbed)-1 or not flowerbed[i+1]):
                cnt+=1
                flowerbed[i]=1
                i+=2
            else:
                i+=1
        return cnt>=n

a1=Solution()

print(a1.canPlaceFlowers([1,0,0,0,1],1))