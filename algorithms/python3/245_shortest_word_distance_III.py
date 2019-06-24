class Solution:
    def shortestWordDistance(self, words: List[str], word1: str, word2: str) -> int:
        res=len(words)
        pos=[-1,-1]
        is_same=word1==word2
        for i in range(len(words)):
            if words[i]==word1:
                if is_same:
                    if pos[0]<=pos[1]:
                        pos[0]=i
                    else:
                        pos[1]=i
                else:
                    pos[0]=i
            elif words[i]==word2:
                pos[1]=i
            if pos[0]>=0 and pos[1]>=0:
                res=min(res,abs(pos[0]-pos[1]))
        if pos[1]==-1:
            res=1
        return res