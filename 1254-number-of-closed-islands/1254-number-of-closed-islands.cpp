//1 - island
//0 - not island
//3 - visiting
//-1 - not visited
class Solution {
private:
    bool isValid(int x, int y, vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();

        return x < rows
            && y < cols
            && x >= 0
            && y >= 0;
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int currX, int currY){
        if(grid[currX][currY] == 1){
            return true;
        }

        
        dp[currX][currY] = 3;        
        int xDir[4] = {1, -1, 0, 0};
        int yDir[4] = {0, 0, 1, -1};
        for(int k = 0; k < 4; k++){
            int nextX = currX + xDir[k];
            int nextY = currY + yDir[k];
            if(!isValid(nextX, nextY, grid)){
                dp[currX][currY] = 0;
                return false; 
            } else if(dp[nextX][nextY] == -1){
                if(!dfs(grid, dp, nextX, nextY)){
                    dp[currX][currY] = 0;
                    return false; 
                }
            } else if(dp[nextX][nextY] == 0){
                dp[currX][currY] = 0;
                return false; 
            } 
        }

        dp[currX][currY] = 1;
        return true;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int noOfIslands = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0 && dp[i][j] == -1){
                    if(dfs(grid, dp, i, j)){
                        noOfIslands++;
                    }
                }
            }
        }

        return noOfIslands;
    }
};