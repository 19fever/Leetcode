class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        
        for (size_t i = 0; i < numRows; i++) {
            vector<int> row;
            for (size_t j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.push_back(1);
                }
                else {
                    row.push_back(result[i-1][j-1] + result[i-1][j]);
                }
            }
            result.push_back(row);
        }
        
        return result;
    }
};
