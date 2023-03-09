class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n, 0));
        
        int row = matrix.size();
        int col = matrix[0].size();

        int cur_row = 0;
        int cur_col = -1;
        int left_bound = -1;
        int right_bound = col;
        int up_bound = 0;
        int down_bound = row;
        int num = 1;
        while (num <= n * n) {
            if (++cur_col == right_bound) {
                break;
            }
            for (; cur_col < right_bound; cur_col++) {
                matrix[cur_row][cur_col] = num++;
            }
            right_bound--;
            cur_col--;
            if (++cur_row == down_bound) {
                break;
            }
            for (; cur_row < down_bound; cur_row++) {
                matrix[cur_row][cur_col] = num++;
            }
            down_bound--;
            cur_row--;

            if (--cur_col == left_bound) {
                break;
            }
            for (; cur_col > left_bound; cur_col--) {
                matrix[cur_row][cur_col] = num++;
            }
            left_bound++;
            cur_col++;
            if (--cur_row == up_bound) {
                break;
            }
            for (; cur_row > up_bound; cur_row--) {
                matrix[cur_row][cur_col] = num++;
            }
            up_bound++;
            cur_row++;
        }
        return matrix;

    }
};
