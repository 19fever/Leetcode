class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int maxP = 0;
        
        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i-1] > 0) {
                maxP += prices[i] - prices[i-1];
            }
        }
        
        return maxP;
    }
};
