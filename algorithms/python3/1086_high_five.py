class Solution(object):
    def highFive(self, items):
        """
        :type items: List[List[int]]
        :rtype: List[List[int]]
        """
        scores=collections.defaultdict(list)
        for id, score in items:
            scores[id].append(score)
        return ([ [id,sum(heapq.nlargest(5,score))//5] for id, score in sorted(scores.items(),key=lambda x: x[0],reverse=False)])
