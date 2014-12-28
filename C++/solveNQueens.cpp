class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<int> s(n, 0);
        dfs(s, result, 0, n);
        
        return result;
    }
    
    void dfs(vector<int> s, vector<vector<string> > &result, int row, int n) {
        if (row == n) {
            vector<string> solution;
            for (int i = 0; i < n; i++) {
                string str(n, '.');
                str[s[i]] = 'Q';
                solution.push_back(str);
            }
            result.push_back(solution);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            s[row] = i;
            if(valid(row, s)) {
                dfs(s, result, row + 1, n);
            }
        }
    }
    
    bool valid(int row, vector<int> colOfRows) {
        for (int i = 0; i < row; i++) {
            if (colOfRows[i] == colOfRows[row] || abs(colOfRows[i] - colOfRows[row]) == row - i) {
                return false;
            }
        }
        
        return true;
    }
};
