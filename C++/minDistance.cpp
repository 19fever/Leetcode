class Solution {
public:
    int minDistance(string word1, string word2) {
        const size_t len1 = word1.size();
        const size_t len2 = word2.size();
        
        int dp[len1 + 1][len2 + 1];
        
        for (size_t i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        
        for (size_t i = 0; i <= len2; i++) {
            dp[0][i] = i;
        }
        
        for (size_t i = 1; i <= len1; i++) {
            for (size_t j = 1; j <= len2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                }
            }
        }
        
        return dp[len1][len2];
    }
};
