class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        
        vector<vector<int> > result;
        vector<int> path;
        subsets(S, result, path, 0);
        return result;
    }
    
    void subsets(vector<int> S, vector<vector<int> > &result, vector<int> &path, int step) {
        if(step == S.size()) {
            result.push_back(path);
            return;
        }
        
        subsets(S, result, path, step + 1);
        path.push_back(S[step]);
        subsets(S, result, path, step + 1);
        path.pop_back();
    }
};
