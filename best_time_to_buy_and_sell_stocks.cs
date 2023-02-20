public class Solution {
    public int MaxProfit(int[] prices) {
        var maxProfit = 0;
        var minPrice = prices[0];
        
        for(int i = 1; i<prices.Length; ++i){
            var sell = prices[i];
            var profit = sell - minPrice;
            if(profit>maxProfit) maxProfit = profit;
            
            if(prices[i] < minPrice) minPrice = prices[i];
        }
        return maxProfit;
    }
}