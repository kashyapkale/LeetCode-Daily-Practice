class Cell{
public:
    int row_index;
    int col_index;
    int distance;
    Cell(int i, int j, int k){
        row_index = i;
        col_index = j;
        distance = k;
    }
};

class Solution {
private:
    bool isPossible(int i, int j, int row, int col){
        return i < row
            && j < col
            && i >= 0
            && j >= 0;
    }


public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
              int row = mat.size();
              int col = mat[0].size();
              vector<vector<int>> visited(row, vector<int>(col, 0));
              vector<vector<int>> distance_arr(row, vector<int>(col, 0));                

              queue<Cell> bfsQ;
              for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(mat[i][j] == 0){
                        Cell cell(i, j, 0);
                        bfsQ.push(cell);
                        visited[i][j] = 1;
                    }
                }
              }


              while(!bfsQ.empty()){
                 Cell top_cell = bfsQ.front();
                 bfsQ.pop();
                 
                 int i = top_cell.row_index;
                 int j = top_cell.col_index;
                 int curr_dis = top_cell.distance;
                 distance_arr[i][j] = curr_dis;

                 int xArr[4] = {1, -1, 0, 0};
                 int yArr[4] = {0, 0, -1, 1};
                 for(int ind = 0; ind<4; ind++){
                    int nextX = i + xArr[ind];
                    int nextY = j + yArr[ind];
                    if(isPossible(nextX, nextY, row, col) && visited[nextX][nextY] == 0){
                        Cell cell(nextX, nextY, curr_dis + 1);
                        bfsQ.push(cell);
                        visited[nextX][nextY] = 1;
                    }
                 }
              }

              return distance_arr;
    }
};