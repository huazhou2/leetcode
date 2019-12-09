class Solution(object):
    def numEquivDominoPairs(self, dominoes):
        """
        :type dominoes: List[List[int]]
        :rtype: int
        """
        dict={}
        res=0
        for item in dominoes:
            key=min(item)*10+max(item)
            if key in dict:
                res+=dict[key]
                dict[key]+=1
            else:
                dict[key]=1
        return res


a=Solution()

print(a.numEquivDominoPairs([[1,2],[1,2],[1,1],[1,2],[2,2]]))


