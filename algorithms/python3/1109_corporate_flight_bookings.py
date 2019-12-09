class Solution(object):
    def corpFlightBookings(self, bookings, n):
        """
        :type bookings: List[List[int]]
        :type n: int
        :rtype: List[int]
        """
        res=[0]*n
        for i,j,k in bookings:
            res[i-1]+=k
            if j<n:
                res[j]-=k
        for i in range(1,len(res)):
            res[i]+=res[i-1]
        return res




a=Solution()

bookings = [[1,2,10],[2,3,20],[2,5,25]]

print(a.corpFlightBookings(bookings,5))
