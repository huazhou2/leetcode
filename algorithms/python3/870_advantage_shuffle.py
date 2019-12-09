class Solution(object):
    def advantageCount(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        sortedA=sorted(A)
        sortedB=sorted(B)
        ind=sorted(range(len(B)),key=lambda x:B[x])

        res=[None]*len(A)
        remaining=[]
        i=0
        for a in sortedA:
            if a>sortedB[i]:
                res[ind[i]]=a
                i+=1
            else:
                remaining.append(a)
        for i in range(len(res)):
            if not res[i]:
                cur=remaining.pop()
                res[i]=cur
        return res

a=Solution()
A = [2,7,11,15]
B = [1,10,4,11]
print(a.advantageCount(A,B))



