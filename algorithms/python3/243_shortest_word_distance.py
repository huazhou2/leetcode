class Solution:
    def shortestDistance(self, words: List[str], word1: str, word2: str) -> int:
        res=len(words)
        pos=[-1,-1]
        for i in range(len(words)):
            if words[i]==word1:
                pos[0]=i
            elif words[i]==word2:
                pos[1]=i
            if pos[0]>=0 and pos[1]>=0:
                res=min(res,abs(pos[0]-pos[1]))
        return res

a=Solution()

words = ["practice", "makes", "perfect", "coding", "makes"]

print(a.shortestDistance(words,'coding','practice'))
