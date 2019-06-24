from typing import List
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans=[]
        new_cover=[i for i in newInterval]
        for interval in intervals:
            if new_cover[0]<=interval[0]<=new_cover[1] or new_cover[0]<=interval[1]<=new_cover[1] or (interval[0]<new_cover[0] and interval[1]>new_cover[1]):
                new_cover[0]=min(interval[0],new_cover[0])
                new_cover[1]=max(interval[1],new_cover[1])
            else:
                ans.append(interval)
        ans.append(new_cover)
        ans.sort(key=lambda x:x[0])
        return ans

a=Solution()

print(a.insert([[1,3],[6,9]],[2,5]))
print(a.insert([[1,2],[3,5],[6,7],[8,10],[12,16]],[4,8]))
