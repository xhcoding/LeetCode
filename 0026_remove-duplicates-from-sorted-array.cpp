class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 1;
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                slow++;
                if (slow != fast) {
                    nums[slow] = nums[fast];
                }
            }
            fast++;
        }
        return slow + 1;
    }
};
