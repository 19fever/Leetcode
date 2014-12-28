class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.size();
        vector<int> steps(n);
        
        steps[0] = 1;
        steps[1] = 0;
        if (s[1] != '0') steps[1] += 1;
        if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) steps[1] += 1;
        
        for (size_t i = 2; i < n; i++) {
            steps[i] = 0;
            if (s[i] != '0') {
                steps[i] += steps[i-1];
            }
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                steps[i] += steps[i-2];
            }
            if (steps[i] == 0) return 0;
        }
        
        return steps[n-1];
    }
};
