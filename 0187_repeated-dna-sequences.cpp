class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        array<char, 26> table;
        table['A' - 'A'] = 1;
        table['C' - 'A'] = 2;
        table['G' - 'A'] = 3;
        table['T' - 'A'] = 4;
        
        unordered_set<int> window;
        
        int left = 0;
        int right = 0;
        unordered_set<string> result;
        
        int windowHash = 0;
        
        int hex = 4;
        int length = 10;
        int hexLength = pow(hex, length - 1);
        
        while (right < s.size()) {
            char c = s[right];
            windowHash = windowHash * hex + table[c - 'A'];
            
            right++;
            if (right - left == length) {
                if (window.count(windowHash)) {
                    result.emplace(s.substr(left, length));
                } else {
                    window.emplace(windowHash);
                }
                windowHash = windowHash - table[s[left] - 'A'] * hexLength;
                left++;
            }
        }
        return vector<string>(result.cbegin(), result.cend());
    }
};
