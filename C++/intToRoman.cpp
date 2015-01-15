class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector<int> digit = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int i = 0;
        while (num > 0) {
            int k = num / digit[i];
            for(int j = 0; j < k; j++) {
                result += roman[i];
            }
            num %= digit[i];
            i++;
        }
        return result;
    }
};
