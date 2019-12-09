class Solution(object):
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        cnts=[]
        for i in range(len(A)):
            cnts.append(collections.Counter(A[i]))
        res=[]


        if not cnts or not cnts[0]:
            return res

        for letter in cnts[0].keys():
            cur_cnt=cnts[0][letter]
            for i in range(len(cnts)):
                cur_cnt=min(cur_cnt,cnts[i][letter])
            if cur_cnt:
                res.extend([letter]*cur_cnt)

        return res

a=Solution()

print(a.commonChars(["bella","label","roller"]))


