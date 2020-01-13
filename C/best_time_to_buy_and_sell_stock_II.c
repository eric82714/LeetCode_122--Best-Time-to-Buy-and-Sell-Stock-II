int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0 || pricesSize == 1) return 0;
        
    int profit = 0;
    int sub_profit = 0;
    int low_price = prices[0];
    int peak_price = 0;
        
    for(int i = 0; i < pricesSize; i++) {
        if(prices[i] < low_price || prices[i] < peak_price) { 
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
