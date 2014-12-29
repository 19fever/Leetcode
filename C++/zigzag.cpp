class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;
        int size = 2 * nRows - 2;
        string result;
        for (size_t i = 0; i < nRows; i++) {
            for (size_t j = i; j < s.size(); j += size) {
                result.append(1, s[j]);
                
                if (i != 0 && i != nRows - 1) {
                    int index = j + (nRows - 1 - i) * 2;
                    if (index < s.size()) result.append(1, s[index]);
                }
            }
        }
        
        return result;
    }
};
