class Solution(object):
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        start=0
        res=[]
        for i in range(len(S)):
            if i==len(S)-1 or S[i]!=S[i+1]:
                if i-start+1>=3:
                    res.append([start,i])
                start=i+1
        return res



a=Solution()
print(a.largeGroupPositions("abcdddeeeeaabbbcd"))

