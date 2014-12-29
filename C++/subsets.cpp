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
        if(step == S.size()) {
            result.push_back(path);
            return;
        }
        
        dfs(S, result, path, step + 1);
        path.push_back(S[step]);
        dfs(S, result, path, step + 1);
        path.pop_back();
    }
};
