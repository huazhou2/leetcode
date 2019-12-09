class Solution(object):
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        goal=(sum(A)-sum(B))//2
        bset=set(B)
        for item  in A:
            if item-goal in bset:
                return [item,item-goal]

a=Solution()

A=[1,2,5]
B = [2,4]
print(a.fairCandySwap(A,B))
