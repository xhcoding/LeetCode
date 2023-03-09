class Solution {
public:
    // Manacher
    string longestPalindrome(string s) {
        
        std::string converted;
        for (const auto& ch : s) {
            converted.push_back('#');
            converted.push_back(ch);
        }
        converted.push_back('#');
        
        vector<int> lens;

        int center_pos = -1;
        int right_pos = -1;

        int start = 0;
        int end = 0;

        for (int i = 0; i < converted.size(); i++) {
            int cur_len = 0;
            if (i > right_pos) {
                // 超出右边界，无法利用前面的信息忽略扩展的长度
                cur_len = expand(converted, i, i);
            } else {
                // 没有超出右边界，先找出 i 关于 center_pos 的对称点
                int i_sym = 2 * center_pos - i;
                // 忽略的扩展长度为 i_sym 的回文长度与 i 到右边界长度的较小值
                int ignore_len = min(lens[i_sym], right_pos - i);
                // 计算扩展长度
                cur_len = expand(converted, i - ignore_len, i + ignore_len);
            }

            lens.push_back(cur_len);

            if (i + cur_len > right_pos) {
                center_pos = i;
                right_pos = i + cur_len;
            }
            if (cur_len * 2 > end - start) {
                start = i - cur_len;
                end = i + cur_len;
            }
        }
        string result;
        for (int i = start + 1; i <= end; i = i + 2) {
            result.push_back(converted[i]);
        }
        
        return result;
    }

    int expand(const string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return (r - l - 2) / 2;
    }

    // string longestPalindrome(string s) {
    //     string res;
    //     for (int i = 0; i < s.size(); i++) {
    //         const string& s1 = expand(s, i, i);
    //         const string& s2 = expand(s, i, i + 1);
    //         res = res.size() > s1.size() ? res : s1;
    //         res = res.size() > s2.size() ? res : s2;
    //     }
    //     return res;
    // }

    //     string expand(const string& s, int l, int r) {
    //         while (l >= 0 && r < s.size() && s[l] == s[r]) {
    //             l--;
    //             r++;
    //         }
    //         return string(s, l + 1, r - l - 1);
    //     }
};
