class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:

        groups={}
        for r, row in enumerate(matrix):
            for c, val in enumerate(row):
                if r-c not in groups:
                    groups[r-c]=val
                elif groups[r-c]!=val:
                    return False
        return True


a=Solution()
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]

print(a.isToeplitzMatrix(matrix))