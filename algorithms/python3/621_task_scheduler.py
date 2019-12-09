class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        counter=collections.Counter(tasks)
        hq=[(-num,task) for task, num in counter.items()]
        heapq.heapify(hq)

        ans=0
        while hq:
            out_item=[]
            for i in range(n+1):
                if hq:
                    num,task=heapq.heappop(hq)
                    ans+=1
                    num+=1
                    if num<0:
                        out_item.append((num,task))
                elif out_item:
                    ans+=n-i+1
                    break
            for item in out_item:
                heapq.heappush(hq,item)

        return ans

