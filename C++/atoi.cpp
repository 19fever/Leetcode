class Solution {
public:
    int atoi(const char *str) {
        int sign = 1;
        int i = 0;
        int n = strlen(str);
        int num = 0;
        while (i < n && str[i] == ' ') {
            i++;
        }
        if (i < n && str[i] == '+') {
            i++;
        }
        else if (i < n && str[i] == '-') {
            sign = -1;
            i++;
        }
        
        while(i < n && str[i] >= '0' && str[i] <= '9') {
            if (INT_MAX / 10 < num || (INT_MAX / 10 == num && str[i] >= '8')) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 + str[i] - '0';
            i++;
        }
        
        return sign * num;
    }
};
