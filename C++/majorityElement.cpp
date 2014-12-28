class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 0;
        int candidate;
        for (int i = 0; i < num.size(); i++) {
            if (count == 0) {
                candidate = num[i];
            }
            
            if (candidate == num[i]) {
                count++;
            }
            else {
                count--;
            }
        }
        
        return candidate;
    }
};
