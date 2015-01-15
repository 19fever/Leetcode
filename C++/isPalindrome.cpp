class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int div = 1;
        while(x / div >= 10) {
            div *= 10;
        }
        while(x > 0) {
            int left = x / div;
            int right = x % 10;
            if(left!=right) {
                return false;
            }
            //delete the left most number
            x %= div;
            //delete the right most number
            x /= 10;
            div /= 100;
        }
        return true;
    }
};
