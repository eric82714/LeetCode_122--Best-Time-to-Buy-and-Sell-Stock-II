class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0 or len(prices) == 1: return 0
        
        profit = 0
        sub_profit = 0
        low_price = prices[0]
        peak_price = 0
        
        for i in range(len(prices)):
            if prices[i] < low_price or prices[i] < peak_price: 
                profit += sub_profit
                sub_profit = 0
                peak_price = 0
                low_price = prices[i]
            if prices[i] - low_price > sub_profit:
                sub_profit = prices[i] - low_price
                peak_price = prices[i]
                      
        return profit + sub_profit
