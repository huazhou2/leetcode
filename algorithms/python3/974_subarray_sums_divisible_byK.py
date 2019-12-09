class Solution(object):
    def subarraysDivByK(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        ##by doing some C selections
        P=[0]

        for x in A:
            P.append((P[-1]+x) % K)
        import collections
        cnts=collections.Counter(P)

        ans=0
        for v in cnts.values():
            ans+=v*(v-1)/2
        return ans

a=Solution()

print(a.subarraysDivByK([4,5,0,-2,-3,1],5))
