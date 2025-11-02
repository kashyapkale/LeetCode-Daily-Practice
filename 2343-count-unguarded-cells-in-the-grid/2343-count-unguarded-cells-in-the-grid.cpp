class Solution {
private:
    bool isValidCell(int m, int n, int row, int col, vector<vector<int>> &visited){
        return (row < m) && (row >= 0) && (col < n) && (col >= 0) && (visited[row][col] == -1 || visited[row][col] == 0);
    }

    int countUnguardedUtil(int m, int n, vector<int>& guard, vector<vector<int>> &visited) {
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};

        int gaurdedCells = 0;
        for(int i = 0; i < 4; i++){
            int curr_x = guard[0];
            int curr_y = guard[1];
            bool continueDirection = true;
            while(continueDirection){
                curr_x += dir_x[i];
                curr_y += dir_y[i];

                if(!isValidCell(m, n, curr_x, curr_y, visited)){
                    continueDirection = false;
                    continue;
                }

                if(visited[curr_x][curr_y] != 0){
                    visited[curr_x][curr_y] = 0;
                    gaurdedCells++;
                }
            }
        }

        return gaurdedCells;
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        for(auto wall : walls){
            visited[wall[0]][wall[1]] = 1;
        }

        for(auto gaurd : guards){
            visited[gaurd[0]][gaurd[1]] = 1;
        }

        int gaurdedCells = 0;
        for(auto gaurd : guards){
            gaurdedCells += countUnguardedUtil(m, n, gaurd, visited);  
        }

        return (m * n) - gaurdedCells - walls.size() - guards.size();
    }
};