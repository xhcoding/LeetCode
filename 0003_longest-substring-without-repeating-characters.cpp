class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 128> window;
        window.fill(-1);
        
        int left = 0;
        int right = 0;
        int length = 0;
        while (right < s.size()) {
            char c = s[right];
            
            // 窗口中 c 的位置比 left 大，说明 c 在 [left, right) 这个区间
            // 出现重复的 c
            if (window[c] >= left) {
                // left 直接移动到 c 的后一个位置，即将前面重复的 c 排除
                left = window[c] + 1;
                // 更新 c 的位置
                window[c] = right;
            } else {
                // 窗口中还没有这个字符，记录位置
                window[c] = right;
            }
            
            right++;
            
            // 更新窗口的长度
            if (length < right - left) {
                length = right - left;
            }
        }
        return length;
    }
};
