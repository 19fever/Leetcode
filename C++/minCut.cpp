ass Solution {
public:
    int minCut(string s) {
        int n = s.size();
        bool mp[n][n];
        int cut[n+1];
        
        for (int i = 0; i <= n; i++) {
            cut[i] = n - 1 - i;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                mp[i][j] = (s[i] == s[j]) && (j - i < 2 || mp[i+1][j-1]);
                if (mp[i][j]) {
                    cut[i] = min(cut[i], cut[j+1] + 1);
                }
            }
        }
        
        return cut[0];
    }
};
