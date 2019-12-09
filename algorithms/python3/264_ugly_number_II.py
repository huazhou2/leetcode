from heapq import heappop, heappush
class Ugly(object):
    def __init__(self):
        seen={1,}
        heap=[]
        heappush(heap,1)
        self.nums=[]
        for _ in range(1690):
            cur_ugly=heappop(heap)
            self.nums.append(cur_ugly)
            for x in [2,3,5]:
                new_ugly=cur_ugly*x
                if new_ugly not in seen:
                    seen.add(new_ugly)
                    heappush(heap,new_ugly)

class Solution(object):
    u1=Ugly()
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.u1.nums[n-1]
a=Solution()

print(a.nthUglyNumber(10))


