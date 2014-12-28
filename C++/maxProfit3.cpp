class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int min = INT_MAX;
        int max = INT_MIN;
        int maxP = 0;
        int dp_lr[n];
        int dp_rl[n];
        
        for (size_t i = 0; i < n; ++i) {
            if (prices[i] < min) {
                min = prices[i];
            }
            if (prices[i] - min > maxP) {
               maxP = prices[i] - min;
            }
            dp_lr[i] = maxP;
        }
        
        maxP = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            if (prices[i] > max) {
                max = prices[i];
            }
            if (max - prices[i] > maxP) {
                maxP = max - prices[i];
            }
            dp_rl[i] = maxP;
        }
        
        maxP = 0;
        
        for (size_t i = 0; i < n - 1; ++i) {
            if (dp_lr[i] + dp_rl[i+1] > maxP) {
                maxP = dp_lr[i] + dp_rl[i+1];
            }
        }
        
        if (dp_lr[n-1] > maxP) {
            maxP = dp_lr[n-1];
        }
        
        return maxP;
    }
};
