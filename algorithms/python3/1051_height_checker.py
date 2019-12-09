class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        res=sorted(heights)

        ans=0
        for i in range(len(heights)):
            if heights[i]!=res[i]:
                ans+=1
        return ans
