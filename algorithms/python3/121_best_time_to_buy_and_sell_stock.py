class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        max1=prices.copy()
        max2=prices.copy()
        for i in range(1,len(prices)):
            if max1[i]>max1[i-1]:
                max1[i]=max1[i-1]
            if max2[len(prices)-i-1]<max2[len(prices)-i]:
                max2[len(prices)-i-1]=max2[len(prices)-i]
        return max([a-b for a,b in zip(max2,max1)])
    def maxProfit2(self, prices: List[int]) -> int:
        maxprofit=0
        minprice=float('inf')
        for i in range(len(prices)):
            if prices[i]<minprice:
                minprice=prices[i]
            elif prices[i]-minprice>maxprofit:
                maxprofit=prices[i]-minprice
        return maxprofit
a=Solution()

print(a.maxProfit2([7,1,5,3,6,4]))

