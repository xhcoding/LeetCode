class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<Card> card2;
        for (int i = 0; i < nums2.size(); i++) {
            card2.push_back({nums2[i], i});
        }
        sort(nums1.begin(), nums1.end());
        sort(card2.begin(), card2.end(), [](const auto& left, const auto& right){
            return left.num > right.num;
        });
        
        vector<int> result;
        result.resize(nums1.size());

        int left = 0;
        int right = nums1.size() - 1;
        for (const auto& c : card2) {
            if (nums1[right] > c.num) {
                result[c.index] = nums1[right];
                right--;
            } else {
                result[c.index] = nums1[left];
                left++;
            }
        }
        return result;
    }

    struct Card {
        int num;
        int index;
    };
};
