class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        for (const auto& num : nums) {
            if (left < num) {
                left = num;
            }
            right += num;
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int curK = split(nums, mid);
            if (curK > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    int split(const vector<int>& nums, int minSum) {
        int curSum = 0;
        int curK = 1;
        for (const auto& num : nums) {
            curSum += num;
            if (curSum > minSum) {
                curK += 1;
                curSum = num;
            }
        }
        return curK;
    }
};
