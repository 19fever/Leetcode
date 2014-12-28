ass Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        
        for (auto it = strs.begin(); it != strs.end(); it++) {
            string str = *it;
            sort(str.begin(), str.end());
            mp[str].push_back(*it);
        }
        
        vector<string> result;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second.size() > 1) {
                result.insert(result.end(), it->second.begin(), it->second.end());
            }
        }
        
        return result;
    }
};
