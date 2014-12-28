class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> flag(s.size() + 1, false);
        flag[0] = true;
        for (int i = 1; i < flag.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (flag[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    flag[i] = true;
                    break;
                }
            }
        }
        return flag[s.size()];
    }
};
