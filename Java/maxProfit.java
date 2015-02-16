public class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int maxp = 0;

        if (prices.length < 2) return 0; 

        for (int i = 0; i < prices.length; i++) {
            min = Math.min(prices[i], min);
            maxp = Math.max(prices[i] - min, maxp);
        }

        return maxp;
    }
}
