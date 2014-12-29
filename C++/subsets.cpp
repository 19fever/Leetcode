class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        
        vector<vector<int> > result;
        vector<int> path;
        dfs(S, result, path, 0);
        return result;
    }
    
    void dfs(const vector<int> &S, vector<vector<int> > &result, vector<int> &path, int step) {
        result.push_back(path);
        
        for (size_t i = step; i < S.size(); i++) {
            path.push_back(S[i]);
            dfs(S, result, path, i + 1);
            path.pop_back();
        }
    }
};
