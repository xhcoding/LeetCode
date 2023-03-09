class Solution {
public:
    Solution(vector<int>& w) {
        prefixSum.resize(w.size() + 1, 0);
        for (int i = 0; i < w.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + w[i];
        }
        srand((unsigned)time(NULL)); 
    }
    
    int pickIndex() {
        int limit = (prefixSum[prefixSum.size() - 1]);
        int randNum = limit == 0 ? 0 : 1 + rand() % prefixSum[prefixSum.size() - 1];
        int left = 1;
        int right = prefixSum.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] == randNum) {
                right = mid;
            } else if (prefixSum[mid] < randNum) {
                left = mid + 1;
            } else if (prefixSum[mid] > randNum) {
                right = mid;
            }
        }
        return left - 1;
    }
    
    vector<int> prefixSum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
