class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        cash,hold=0,-prices[0]
        for i in range(len(prices)):
            cash=max(cash,hold+prices[i]-fee)
            hold=max(hold,cash-prices[i])
        return cash


a=Solution()
prices=[1, 3, 2, 8, 4, 9]

print(a.maxProfit(prices,2))