class Solution(object):
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        if not M:
            return None
        r,c=len(M),len(M[0])
        res=[[0]*c for i in range(r)]

        for i in range(r):
            for j in range(c):
                r1,r2=max(i-1,0),min(i+2,r)
                c1,c2=max(j-1,0),min(j+2,c)
                cnt=0
                tmp=0
                for k in range(r1,r2):
                    for m in range(c1,c2):
                        tmp+=M[k][m]
                        cnt+=1
                res[i][j]=tmp//cnt

        return res

a=Solution()
m=[[1,1,1],[1,0,1],[1,1,1]]
print(a.imageSmoother(m))