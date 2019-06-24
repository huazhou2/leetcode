from typing import List
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n=len(digits)
        addition=1
        for i in range(n-1,-1,-1):
            digits[i],addition=(digits[i]+addition) % 10,(digits[i]+addition) // 10
            if not addition:
                break
        if addition:
            digits.insert(0,addition)
        return digits


a=Solution()

nums=[1,2,3]
a.plusOne(nums)
