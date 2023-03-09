class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end()) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int actualHour = spent(piles, mid);
            if (actualHour > h) {
                left = mid + 1;
            } else {
                right =  mid;
            }
        }
        return left;
    }
    
    int spent(const vector<int>& piles, int speed) {
        int h = 0;
        for (const auto& pile : piles) {
            h += (pile + speed - 1) / speed;
        }
        return h;
    }
};
