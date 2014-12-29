class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        
        vector<vector<int> > result;
        vector<int> path;
        dfs(S,path,result,0);
        
        return result;
    }
    
    void dfs(const vector<int> &S, vector<int> &path, vector<vector<int> > &result, int start) {
        result.push_back(path);
        
        for (size_t i = start; i < S.size(); i++) {
            if (i != start && S[i] == S[i-1]) continue;
            path.push_back(S[i]);
            dfs(S, path, result, i + 1);
            path.pop_back();
        }
    }
};

