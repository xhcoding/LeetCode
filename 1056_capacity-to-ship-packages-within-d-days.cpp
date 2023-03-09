class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        for (const auto& weight : weights) {
            if (left < weight) {
                left = weight;
            }
            right += weight;
        }
        right += 1; // [left, right)
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int curDays = spent(weights, mid);
            if (curDays > days ) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    int spent(const vector<int>& weights, int capacity) {
        int day = 1;
        int curCapacity = 0;
        for (const auto& weight : weights) {
            curCapacity += weight;
            if (curCapacity > capacity) {
                day += 1;
                curCapacity = weight;
            }
        }
        return day;
    }
};
