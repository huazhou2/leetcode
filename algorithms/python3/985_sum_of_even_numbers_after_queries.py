class Solution(object):
    def sumEvenAfterQueries(self, A, queries):
        """
        :type A: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        res=[]
        cur=sum([x for x in A if x %2==0])
        for val, ind in queries:
            if A[ind] %2==0:
                cur-=A[ind]
            A[ind]+=val
            if A[ind] % 2==0:
                cur+=A[ind]
            res.append(cur)
        return  res


a=Solution()
A = [1,2,3,4]
queries = [[1,0],[-3,1],[-4,0],[2,3]]
print(a.sumEvenAfterQueries(A,queries))

