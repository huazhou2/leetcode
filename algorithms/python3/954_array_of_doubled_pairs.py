class Solution(object):
    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        import collections
        cnts=collections.Counter(A)

        temp=sorted(A,key=abs,reverse=True)
        for item in temp:
            print(cnts)
            if cnts[item]>0:
                if cnts[item/2]>=cnts[item]:
                    cnts[item/2]-=cnts[item]
                    cnts[item]=0
                else:
                    return False
        return True



a=Solution()

print(a.canReorderDoubled([3,1,3,6]))