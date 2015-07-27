class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        
        while(left <= right) {
            
            while (left < right && nums[left] == nums[right]) {
                left++;
            }
            
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            if (nums[mid] < target) {
                if (nums[mid] > nums[right] || nums[right] >= target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if (nums[mid] < nums[left] || nums[left] <= target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};