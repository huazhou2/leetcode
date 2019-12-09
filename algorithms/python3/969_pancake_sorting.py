class Solution(object):
    def pancakeSort(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        res=[]
        n=len(A)
        end=n-1
        B=sorted(A)
        def flip(arr,k):
            for i in range(k//2):
                arr[i],arr[k-i-1]=arr[k-i-1],arr[i]

        for i in range(n-1,-1,-1):
            curind=A.index(B[i])
            if curind!=i:
                if curind!=0:
                    res.append(curind + 1)
                    flip(A,curind+1)
                flip(A,i+1)
                res.append(i+1)
        return res

a=Solution()

print(a.pancakeSort([3,2,4,1] ))

