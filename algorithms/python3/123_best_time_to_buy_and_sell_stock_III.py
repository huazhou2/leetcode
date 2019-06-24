class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        left_max=[0]*len(prices)
        right_max=[0]*len(prices)
        cur_min=prices[0]
        cur_max=prices[-1]
        for i in range(1,len(prices)):
            if prices[i]<cur_min:
                cur_min=prices[i]
            left_max[i]=max(left_max[i-1],prices[i]-cur_min)
        for i in range(len(prices)-2,-1,-1):
            if prices[i]>cur_max:
                cur_max=prices[i]
            right_max[i]=max(right_max[i+1],cur_max-prices[i])
        return max([a+b for a, b in zip(left_max,right_max)])

a=Solution()

print(a.maxProfit([3,3,5,0,0,3,1,4]))