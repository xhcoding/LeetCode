class Solution {
public:    
    string reverseWords(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
        
        left = 0;
        right = 0;
        string result;
        while (right < s.size()) {
            for (;left < s.size() && s[left] == ' '; left++)
                ;
            if (left >= s.size()) {
                break;
            }
            right = left;
            for (;right < s.size() && s[right] != ' '; right++)
                ;
            int i = left;
            int j = right - 1;
            while (i < j) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                i++;
                j--;
            }
            result += string(s, left, right - left);
            result += ' ';
            left = right;
        }
        result.pop_back();
        return result;
    }
    
};

