class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 255> need{0};
        int size = 0;
        for (const auto& c : s1) {
            if (need[c] == 0) {
                size++;
            }
            need[c]++;
        }
        int left = 0;
        int right = 0;
        array<int, 255> window{0};
        while (left < s2.size() && right < s2.size()) {
            char c = s2[left];
            if (need[c] == 0) {
                left++;
            } else {
                right = left;
                int valid = 0;
                window.fill(0);
                while (right < s2.size()) {
                    char d = s2[right];
                    if (need[d] != 0) {
                        window[d]++;
                        if (window[d] == need[d]) {
                            valid++;
                            if (valid == size) {
                                return true;
                            }
                        } else if (window[d] > need[d]) {
                            while (left < right) {
                                char e = s2[left];
                                window[e]--;
                                left++;
                                if (e != d) {
                                    if (window[e] == need[e] - 1) {
                                        valid--;
                                    }
                                } else {
                                    break;
                                }
                            }
                        }
                        right++;
                    } else {
                        left = right + 1;
                        break;
                    }
                }
            }
        }
        return false;
    }
};
