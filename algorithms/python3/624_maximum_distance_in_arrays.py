class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        ans=0
        min_val=arrays[0][0]
        max_val=arrays[0][-1]
        for i in range(1,len(arrays)):
            ans=max(max_val-arrays[i][0],ans,arrays[i][-1]-min_val)
            max_val=max(max_val,arrays[i][-1])
            min_val=min(min_val,arrays[i][0])
        return ans
