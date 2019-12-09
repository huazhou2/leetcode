class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        r=len(matrix)
        if not r:
            return False
        c=len(matrix[0])
        start,end=0,r*c-1
        while start<=end:
            mid=(start+end)//2
            curr,curc=mid//c,mid%c
            if matrix[curr][curc]==target:
                return True
            elif matrix[curr][curc]>target:
                end=mid-1
            else:
                start=mid+1
        return False


a=Solution()

nums=matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

print(a.searchMatrix(nums,3))