class Solution(object):
    def numSubmatrixSumTarget(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: int
        """
        r,c=len(matrix),len(matrix[0])
        cnt=0
        for k in range(r):
            sumall=[0]*c
            for i in range(k,r):
                vals=collections.defaultdict(int)
                vals[0]=1
                val=0
                for j in range(c):
                    sumall[j]+=matrix[i][j]
                    val+=sumall[j]
                    cnt+=vals[val-target]
                    vals[val]+=1
        return cnt