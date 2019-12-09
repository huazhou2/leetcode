class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool: 
        for i in range(len(A)):
            if A[i]-i>1 or A[i]-i<-1:
                return False
        return True