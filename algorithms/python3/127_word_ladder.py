from collections import defaultdict
from typing import List
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if not beginWord or not endWord or not wordList or not endWord in wordList:
            return 0
        word_dict=defaultdict(list)
        l=len(beginWord)
        for word in wordList:
            for i in range(l):
                word_dict[word[:i]+'*'+word[i+1:]].append(word)
        queue=[(beginWord,1)]
        visited={beginWord:True}
        while queue:
            curword,level=queue.pop(0)
            for i in range(l):
                inter_word=curword[:i]+'*'+curword[i+1:]
                for word in word_dict[inter_word]:
                    if word==endWord:
                        return level+1
                    if word not in visited:
                        visited[word]=True
                        queue.append((word,level+1))
            word_dict[inter_word]=[]
        return 0


