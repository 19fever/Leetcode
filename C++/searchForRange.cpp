class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2);
        
        ret[0] = leftRange(nums, target);
        ret[1] = rightRange(nums, target);
        
        return ret;
    }
    
    int leftRange(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return nums[left] == target ? left : -1;
    }
    
    int rightRange(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = (left + right) - (left + right) / 2;
            
            if (nums[mid] <= target) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }
        
        return nums[left] == target ? left : -1;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        
        ret.push_back(leftRange(nums, target));
        ret.push_back(rightRange(nums, target));
        
        return ret;
    }
    
    int leftRange(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return nums[left] == target ? left : -1;
    }
    
    int rightRange(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return nums[right] == target ? right : -1;
    }
};