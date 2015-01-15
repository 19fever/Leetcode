class Solution {
public:
    int maxArea(vector<int> &height) {
        int L = 0;
        int R = height.size() - 1;
        int result = 0;
        while (L < R) {
            int area = min(height[L], height[R]) * (R - L);
            result = max(result, area);
            if (height[L] < height[R]) {
                L++;
            }
            else {
                R--;
            }
        }
        return result;
    }
};
