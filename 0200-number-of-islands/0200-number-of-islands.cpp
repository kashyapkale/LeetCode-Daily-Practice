class Solution {
private:
    bool isPossible(int row, int col, int i, int j){
        return i < row 
            && i >= 0 
            && j < col 
            && j >= 0 ;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){

        int xDir[4] = {1,-1,0,0};
        int yDir[4] = {0,0,1,-1};

        int row = grid.size();
        int col = grid[0].size();

        grid[i][j] = '9'; 
        for(int k = 0; k < 4; k++){
            int nextX = i + xDir[k];
            int nextY = j + yDir[k];
            if(isPossible(row, col, nextX, nextY)){
                    if(grid[nextX][nextY] == '1')
                        dfs(grid, nextX, nextY);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};