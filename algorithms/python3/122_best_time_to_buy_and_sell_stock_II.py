class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit=0
        for i in range(1,len(prices)):
            if prices[i]>prices[i-1]:
                maxprofit+=prices[i]-prices[i-1]
        return maxprofit

a=Solution()

print(a.maxProfit([1,2,3,4,5]))