class Solution {
public:
    int count;
    int totalNQueens(int n) {
        count = 0;
        int *s = new int[n];
        dfs(s, 0, n);
        return count;
    }
    
    void dfs(int s[], int row, int n) {
        if (row == n) {
            count++;
            return;
        }
        
        for (int i = 0; i < n; i++){
            s[row] = i;
            if (isValid(s, row)) {
                dfs(s, row + 1, n);
            }
        }
    }
    
    bool isValid(int colOfRows[], int row) {
        for (int i = 0; i < row; i++) {
            if (colOfRows[i] == colOfRows[row] || abs(colOfRows[i] - colOfRows[row]) == row - i) {
                return false;
            }
        }
        return true;
    }
};
