class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (;slow < nums.size() && nums[slow] != 0; slow++)
            ;
        int fast = slow + 1;
        
        for (; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                nums[fast] = 0;
                slow++;
            }
        }
    }
};
