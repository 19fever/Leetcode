class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> path;
        dfs(num, target, 0, path, result);
        return result;
    }
    
    void dfs(const vector<int> &num, int diff, int start, vector<int> &path, vector<vector<int> > &result) {
        if (diff == 0) {
            result.push_back(path);
            return;
        }
        
        int pre = -1;
        
        for (size_t i = start; i < num.size(); i++) {
            if (num[i] > diff) return;
            
            if (pre != num[i]) {
                pre = num[i];
                path.push_back(num[i]);
                dfs(num, diff - num[i], i + 1, path, result);
                path.pop_back();
            }
        }
    }
};
