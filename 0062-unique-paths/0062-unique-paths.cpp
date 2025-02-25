class Solution {
private:
    bool isOutOfBound(int row, int col, int m, int n){
        return !((row >= 0 && row < m) && (col >= 0 && col < n));
    }

    int uniquePathsUtil(int row, int col, int m, int n, vector<vector<int>> &dp) {
        if(row == m - 1 && col == n - 1){
            return 1;
        } else if(isOutOfBound(row, col, m, n)){
            return 0;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        return dp[row][col] = uniquePathsUtil(row+1, col, m, n, dp) + uniquePathsUtil(row, col + 1, m, n, dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return uniquePathsUtil(0, 0, m, n, dp);
    }
};