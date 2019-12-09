from typing import List
class Solution:
    def numMatchingSubseq(self, S: str, words: List[str]) -> int:
        ans=0
        heads=[[] for _ in range(26)]
        for word in words:
            it=iter(word)
            heads[ord(next(it))-ord('a')].append(it)

        for letter in S:
            letter_ind=ord(letter)-ord('a')
            old_bucket=heads[letter_ind]
            heads[letter_ind]=[]
            while old_bucket:
                it=old_bucket.pop()
                nxt=next(it,None)
                if nxt:
                    heads[ord(nxt)-ord('a')].append(it)
                else:
                    ans+=1
        return ans




a=Solution()

words = ["a", "bb", "acd", "ace"]


print(a.numMatchingSubseq('abcde',words))
