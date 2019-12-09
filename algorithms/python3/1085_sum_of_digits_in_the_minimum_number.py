class Solution(object):
    def sumOfDigits(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        return( -(sum([int(letter)for letter in str(min(A))]) % 2) +1 )