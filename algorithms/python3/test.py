import math
class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        visited=[False]*N
        cnt=0

        def helper(depth,visited,arr):
            nonlocal cnt
            if depth==N:
                cnt+=1
                print(arr)
            for i in range(N):
                if not visited[i] and ( (depth+1) % (i+1) ==0 or (i+1)%(depth+1)==0 ):
                    visited[i]=True
                    helper(depth+1,visited,arr+[i+1])
                    visited[i]=False
        helper(0,visited,[])
        return cnt


a=Solution()
print(a.countArrangement(4))