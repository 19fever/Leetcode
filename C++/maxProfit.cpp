class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int min = INT_MAX;
        int maxP = 0;
        for (size_t i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            }
            if (prices[i] - min > maxP) {
                maxP = prices[i] - min;
            }
        }
        
        return maxP;
    }
};
