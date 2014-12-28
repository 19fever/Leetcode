class Solution {
public:
    const vector<string> keyboard {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string path;
        dfs(digits, 0, path, result);
        return result;
    }
    
    void dfs(const string &digits, int start, string &path, vector<string> &result) {
        if (start == digits.size()) {
            result.push_back(path);
            return;
        }
        char ch = digits[start];
        for (size_t i = 0; i < keyboard[ch - '0'].size(); i++) {
            path.push_back(keyboard[ch - '0'][i]);
            dfs(digits, start + 1, path, result);
            path.pop_back();
        }
    }
};
