from typing import List
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res=[[1],[1,1]]
        for i in range(2,numRows):
            prev_row=res[i-1]
            cur_row=[1]
            for j in range(len(prev_row)-1):
                cur_row+=[prev_row[j]+prev_row[j+1]]
            res+=[cur_row+[1]]
        return res[:numRows]

a=Solution()

print(a.generate(5))
