class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        import collections
        cnts=collections.Counter(A)

        ans=0
        taken=[]

        for x in range(100000):
            if cnts[x]>=2:
                taken.extend([x]*(cnts[x]-1))
            elif taken and cnts[x]==0:
                ans+=x-taken.pop()
        return ans





a=Solution()

print(a.minIncrementForUnique([3,2,1,2,1,7]))

