class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        res=[0]*len(deck)
        import collections
        temp=collections.deque(range(len(deck)))
        deck.sort()
        cnt=0
        while temp:
            res[temp.popleft()]=deck[cnt]
            if temp:
                first=temp.popleft()
                temp.append(first)
            cnt += 1
        return res

a=Solution()

print(a.deckRevealedIncreasing([17,13,11,2,3,5,7]))


