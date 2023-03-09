class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int valid = 0;

        int start = -1;
        int length = 1000000;

        while (right < s.size()) {
            char c = s[right];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                if (right - left < length) {
                    start = left;
                    length = right - left + 1;
                }
                char d = s[left];
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
                left++;
            }
            right++;
        }
        
        if (start == -1) {
            return "";
        } else {
            return s.substr(start, start + length);
        }
    }
};
