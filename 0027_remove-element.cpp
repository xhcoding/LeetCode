class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = -1;
        int fast = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
