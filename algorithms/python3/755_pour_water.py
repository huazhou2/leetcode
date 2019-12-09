class Solution:
    def pourWater(self, heights: List[int], V: int, K: int) -> List[int]:

        for drop in range(V):
            for d in (-1,1):
                i=best=K
                while 0<=i+d<len(heights) and heights[i+d]<=heights[i]:
                    if heights[i+d]<heights[i]:
                        best=i+d
                    i=i+d
                if best!=K:
                    break
            heights[best]+=1
        return heights



a=Solution()

print(a.pourWater([3,1,3],5,1))