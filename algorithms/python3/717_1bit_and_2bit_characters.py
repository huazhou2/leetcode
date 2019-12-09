class Solution(object):
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        ##basically change all 1,1 to 0 ,0, and then check 2nd to last bit
        if len(bits)<=1:
            return True
        for i in range(len(bits)-1):
            if bits[i] and bits[i+1]:
                bits[i]=0
                bits[i+1]=0
        return bits[-2]==0
