class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        res=[]
        cur_low=lower
        for num in nums+[upper+1]:
            if num==cur_low:
                cur_low=num+1
            elif num>cur_low:
                cur_high=num-1
                if cur_high==cur_low:
                    res.append(str(cur_low))
                else:
                    res.append(str(cur_low)+'->'+str(cur_high))
                cur_low=num+1

        return res



a=Solution()

print(a.findMissingRanges([0, 1, 3, 50, 75],0,99))
