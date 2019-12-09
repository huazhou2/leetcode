class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if not intervals:
            return 0

        res=0

        start_times=sorted([item[0] for item in intervals])
        end_times=sorted([item[1] for item in intervals])
        l1,l2=0,0

        while l1 < len(intervals):
            if start_times[l1]<end_times[l2]:
                res+=1

            else:
                l2+=1
            l1+=1

        return res




