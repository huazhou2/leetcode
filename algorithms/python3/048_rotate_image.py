class Solution:
    def rotate(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(len(matrix)):
            for j in range(0,i):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]

        for i in range(len(matrix)):
            for j in range(len(matrix[0])//2):
                cur=len(matrix[0])-1-j
                matrix[i][j],matrix[i][cur]=matrix[i][cur],matrix[i][j]


a=Solution()

nums=[[1,2,3],[4,5,6],[7,8,9]]

a.rotate(nums)