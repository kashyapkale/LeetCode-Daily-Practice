class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //find the transpose
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++){
            for(int j = i; j < col; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reverse the rows
        for(int i = 0; i < row; i++){
            int l = 0;
            int r = col - 1;
            while(l <= r){
                swap(matrix[i][l],matrix[i][r]);
                l++;
                r--;
            }
        }
    }
};