class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        
        for (size_t i = 0; i < numbers.size(); i++) {
            hash[numbers[i]] = i;
        }
        
        for (size_t i = 0; i < numbers.size(); i++) {
            if (hash.find(target - numbers[i]) != hash.end() && hash[target - numbers[i]] != i) {
                result.push_back(i + 1);
                result.push_back(hash[target - numbers[i]] + 1);
                break;
            }
        }
        
        return result;
    }
};
