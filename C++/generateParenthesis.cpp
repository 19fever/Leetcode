class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if ( n != 0 ) {
            dfs("", 0, 0, n, result);
        }
        return result;
    }
    
    void dfs(string s, int l, int r, int n, vector<string> &result) {
        if (l == n) {
            result.push_back(s.append(n-r, ')'));
            return;
        }
        else {
            dfs(s + '(', l + 1, r, n, result);
            if (l > r) {
                dfs(s + ')', l, r + 1, n, result);
            }
        }
    }
};
