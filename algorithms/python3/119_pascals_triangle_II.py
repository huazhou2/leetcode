from typing import List
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans=[1]
        for i in range(rowIndex):
            cur_res=ans.copy()
            ans=[1]
            for j in range(len(cur_res)-1):
                ans.append(cur_res[j]+cur_res[j+1])
            ans.append(1)
        return ans

a=Solution()
print(a.getRow(2))
