class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        import collections
        import functools
        def gcd (x,y):
            while(y):
                x,y=y,x%y
            return x
            
        count=collections.Counter(deck)
        return functools.reduce(gcd,count.values())>=2

a=Solution()

print(a.hasGroupsSizeX([1,2,3,4,4,3,2,1]))