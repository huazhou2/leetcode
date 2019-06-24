from collections import defaultdict
class WordDistance:

    def __init__(self, words: List[str]):

        self.locations=defaultdict(list)
        for i,word in enumerate(words):
            self.locations[word].append(i)

    def shortest(self, word1: str, word2: str) -> int:
        loc1,loc2=self.locations[word1],self.locations[word2]
        i,j=0,0
        res=float('inf')
        while i<len(loc1) and j<len(loc2):
            res=min(abs(loc1[i]-loc2[j]),res)
            if loc1[i]<loc2[j]:
                i+=1
            else:
                j+=1
        return res


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)

words=["practice", "makes", "perfect", "coding", "makes"]

a=WordDistance(words)