class Solution {
public:
    int strStr(string haystack, string needle) {
        const auto& next = getNext(needle);
        int i = 0;
        int j = 0;
        while (i < haystack.size() && j < static_cast<int>(patternLen)) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == needle.size()) {
            return i - j;
        } else {
            return -1;
        }
    }

    vector<int> getNext(const string& pattern) {
        vector<int> next;
        next.resize(pattern.size(), -1);
        int i = 0;
        int j = -1;
        while (i < pattern.size() - 1) {
            if (j == -1 || pattern[i] == pattern[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        return next;
    }
};
