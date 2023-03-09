class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        array<int, 128> need{0};

        int size = 0;
        for (const auto& c : p) {
            if (need[c] == 0) {
                size++;
            }
            need[c]++;
        }
        
        int left = 0;
        int right = 0;

        array<int, 128> window{0};
        int valid = 0;
        vector<int> result;
        while (right < s.size()) {
            char c = s[right];
            if (need[c] != 0) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }

            }
            right++;
            if (valid == size) {
                result.push_back(left);
            }
            while (right - left >= p.size()) {
                char d = s[left];
                if (need[d] != 0) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
                left++;
            }
        }
        return result;
    }
};
