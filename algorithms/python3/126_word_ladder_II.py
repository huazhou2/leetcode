from collections import defaultdict
from typing import List
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if not beginWord or not endWord or not wordList or not endWord in wordList:
            return []

        word_dict=defaultdict(list)
        l=len(beginWord)
        for word in wordList:
            for i in range(l):
                word_dict[word[:i]+'*'+word[i+1:]].append(word)

        queue=[(beginWord,1)]
        visited={beginWord:1}
        graph=defaultdict(list)
        while queue:
            curword,level=queue.pop(0)
            for i in range(l):
                inter_word=curword[:i]+'*'+curword[i+1:]
                for word in word_dict[inter_word]:
                    if word not in visited:
                        visited[word]=level+1
                        queue.append((word,level+1))
                    if not word==curword and word not in graph[curword]:
                        graph[curword].append(word)

        results=[]
        self.dfs(graph,visited,beginWord,endWord,[beginWord],results)
        return results

    def dfs(self,graph,visited,begin,target,path,results):
        if begin==target:
            results.append(path[:])
        else:
            dist=visited[begin]
            for word in graph[begin]:
                if visited[word]==dist+1:
                    self.dfs(graph,visited,word,target,path+[word],results)

beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

a=Solution()
print(a.findLadders(beginWord,endWord,wordList))