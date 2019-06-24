class Solution(object):
    def longestLine(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        if not M:
            return 0
        r,c=len(M),len(M[0])
        max_len=0
        '''horizontal'''
        for i in range(r):
            cnt=0
            for j in range(c):
                if M[i][j]==1:
                    cnt+=1
                    max_len=max(max_len,cnt)
                else:
                    cnt=0
        '''vertical'''
        for i in range(c):
            cnt=0
            for j in range(r):
                if M[j][i]==1:
                    cnt+=1
                    max_len=max(max_len,cnt)
                else:
                    cnt=0
        '''diaganal'''
        for i in range(r):
            for j in range(c):
                cnt=0
                k,m=i,j
                while k<r and m<c:

                    if M[k][m]==1:
                        cnt+=1
                        max_len=max(max_len,cnt)
                    else:
                        cnt=0
                    k+=1
                    m+=1
        for i in range(r):
            for j in range(c):
                cnt=0
                k,m=i,j
                while k<r and m>=0:
                    if M[k][m]==1:
                        cnt+=1
                        max_len=max(max_len,cnt)
                    else:
                        cnt=0
                    k+=1
                    m-=1
        return max_len


a=Solution()

print(a.longestLine([[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]))

