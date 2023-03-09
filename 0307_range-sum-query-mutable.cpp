class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size() + 1, 0);
        diff.resize(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = nums[i] + prefixSum[i];
        }
    }
    
    void update(int index, int val) {
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
    
    vector<int> prefixSum;
    vector<int> diff;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
