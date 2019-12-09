class Solution(object):
    def addToArrayForm(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: List[int]
        """
        carry=0
        K1=[int(x) for x in str(K)]
        n=min(len(A),len(K1))
        res=[0]*(max(len(A),len(K1))+1)

        if (len(A)>len(K1)):
            num1,num2=A,K1
        else:
            num1,num2=K1,A

        cnt=0
        for i in range(n-1,-1,-1):
            cnt+=1
            temp=A[-cnt]+K1[-cnt]+carry
            res[-cnt]=temp % 10
            carry=temp // 10
        while cnt<= len(num1) or carry :
            cnt+=1
            if cnt<=len(num1):
                temp=num1[-cnt]+carry
            else:
                temp=carry
            res[-cnt]=temp % 10
            carry=temp // 10
        if not res[0]:
            res=res[1:]
        return res






a=Solution()
A = [2,1,5]
K = 806
print(a.addToArrayForm(A,K))

