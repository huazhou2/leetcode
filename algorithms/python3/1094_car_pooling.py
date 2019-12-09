class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        marks=[0]*1001
        for i,j,k in trips:
            marks[j]+=i
            marks[k]-=i
        for i in range(1,len(marks)):
            marks[i]=marks[i-1]+marks[i]
            if marks[i]>capacity:
                return False

        return True
