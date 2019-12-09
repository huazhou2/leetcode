class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans=[]
        intervals.sort(key=lambda x: x[0])

        for interval in intervals:
            if not ans or ans[-1][1]<interval[0]:
                ans.append(interval)
            else:
                ans[-1][1]=max(ans[-1][1],interval[1])
        return ans


a=Solution()
print(a.merge([[1,3],[2,6],[8,10],[15,18]]))



