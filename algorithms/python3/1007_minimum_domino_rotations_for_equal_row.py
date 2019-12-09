class Solution(object):
    def minDominoRotations(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        import collections
        cnts_A=collections.Counter(A)
        cnts_B=collections.Counter(B)
        res=len(A)
        for i in range(1,7):
            if cnts_A[i] +cnts_B[i]>=len(A):
                cur=0
                for j in range(len(A)):
                    if (A[j]!=i):
                        if B[j]==i:
                            cur+=1
                        else:
                            cur=len(A)
                            break
                cur2=0
                for j in range(len(A)):
                    if (B[j] != i):
                        if A[j]==i:
                            cur2 += 1
                        else:
                            cur2 = len(A)
                            break
                cur=min(cur,cur2)
                res=min(cur,res)
        if res==len(A):
            return -1
        else:
            return res
    def minDominoRotations2(selfself,A,B):
        def check(x):
            rot_a=rot_b=0
            for i in range(n):
                if A[i] !=x and B[i]!=x:
                    return -1
                elif A[i]!=x:
                    rot_a+=1
                elif B[i]!=x:
                    rot_b+=1
            return min(rot_a,rot_b)
        n=len(A)

        rotations=check(A[0])
        if rotations != -1 or A[0]==B[0]:
            return rotations
        else:
            return check(B[0])

a=Solution()
A=[1,2,1,1,1,2,2,2]
B= [2,1,2,2,2,2,2,2]

print(a.minDominoRotations2(A,B))

