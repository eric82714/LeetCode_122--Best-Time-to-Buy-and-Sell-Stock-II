class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 or prices.size() == 1) return 0;
        
        int profit = 0;
        int sub_profit = 0;
        int low_price = prices[0];
        int peak_price = 0;
        
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < low_price or prices[i] < peak_price) { 
                profit = profit + sub_profit;
                sub_profit = 0;
                peak_price = 0;
                low_price = prices[i];
            }
            if(prices[i] - low_price > sub_profit) {
                sub_profit = prices[i] - low_price;
                peak_price = prices[i];
            }
        }
        return profit + sub_profit;
    }
};
