class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
        for (size_t i = 0; i < s.size(); i++) {
            for (size_t j = i; j < s.size(); j++) {
                if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                    dp[i][j] = true;
                }
            }
        }
        
        vector<string> path;
        vector<string> result;
        dfs(s, dp, s.size(), path, result);
        return result;
    }
    
    void dfs(const string &s, const vector<vector<bool>> &dp, int cur, vector<string> &path, vector<string> &result) {
        if (cur == 0) {
            string temp;
            for (auto it = path.rbegin(); it != path.rend(); ++it) {
                temp += *it + " ";
            }
            temp.erase(temp.end()-1);
            result.push_back(temp);
            return;
        }
        
        for (size_t i = 0; i < cur; i++) {
            if (dp[i][cur-1]) {
                path.push_back(s.substr(i, cur - i));
                dfs(s, dp, i, path, result);
                path.pop_back();
            }
        }
    }
};
