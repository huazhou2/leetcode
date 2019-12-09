class Solution(object):
    def numMovesStones(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        temp=sorted([a,b,c])
        d1=temp[1]-temp[0]-1
        d2=temp[2]-temp[1]-1
        if d1==0 and d2==0:
            return [0,0]
        elif d1<2 or d2<2:
            return [1,d1+d2]
        else:
            return [2,d1+d2]

a=Solution()

print(a.numMovesStones(3,5,1))
