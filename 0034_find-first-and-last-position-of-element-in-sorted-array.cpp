class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {leftBound(nums, target), rightBound(nums, target)};
    }

    int leftBound(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            }
        }
        if (left >= nums.size()) {
            return -1;
        }
        if (nums[left] == target) {
            return left;
        } else {
            return -1;
        }
    }

    int rightBound(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            }
        }
        if (right - 1 < 0) {
            return -1;
        }
        if (nums[right - 1] == target) {
            return right - 1;
        } else {
            return -1;
        }
    }
};
