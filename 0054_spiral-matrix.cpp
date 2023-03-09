class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();

        int cur_row = 0;
        int cur_col = -1;
        int left_bound = -1;
        int right_bound = col;
        int up_bound = 0;
        int down_bound = row;
        while (result.size() < row * col) {
            if (++cur_col == right_bound) {
                break;
            }
            for (; cur_col < right_bound; cur_col++) {
                result.push_back(matrix[cur_row][cur_col]);
            }
            right_bound--;
            cur_col--;
            if (++cur_row == down_bound) {
                break;
            }
            for (; cur_row < down_bound; cur_row++) {
                result.push_back(matrix[cur_row][cur_col]);
            }
            down_bound--;
            cur_row--;

            if (--cur_col == left_bound) {
                break;
            }
            for (; cur_col > left_bound; cur_col--) {
                result.push_back(matrix[cur_row][cur_col]);
            }
            left_bound++;
            cur_col++;
            if (--cur_row == up_bound) {
                break;
            }
            for (; cur_row > up_bound; cur_row--) {
                result.push_back(matrix[cur_row][cur_col]);
            }
            up_bound++;
            cur_row++;
        }
        return result;
    }
};
