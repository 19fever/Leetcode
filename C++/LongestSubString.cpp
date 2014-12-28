ass Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool flag[256] = {false};
        int n = s.size();
        int max_len = 0;
        int start = 0;
        
        for (int i = 0; i < n; i++) {
            if (flag[s[i]]) {
                max_len = max(max_len, i - start);
                while (s[start] != s[i]) {
                    flag[s[start]] = false;
                    start++;
                }
                start++;
            }
            else {
                flag[s[i]] = true;
            }
        }
        
        return max(max_len, n - start);
    }
};
