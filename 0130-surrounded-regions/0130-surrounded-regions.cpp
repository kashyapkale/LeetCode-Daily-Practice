//-1 - not turn
//0 - not visited

class Solution {
private:
    bool isPossible(int i, int j, int row, int col){
        return i < row
            && j < col
            && i >= 0
            && j >= 0;
    }

    void bfs(vector<vector<char>>& board, vector<vector<int>> &visited, int i, int j) {
        int row = board.size();
        int column = board[0].size();
        visited[i][j] = -1;
        
        int xArr[4] = {1, -1, 0, 0};
        int yArr[4] = {0, 0, -1, 1};
        for(int ind = 0; ind<4; ind++){
            int nextX = i + xArr[ind];
            int nextY = j + yArr[ind];
            if(isPossible(nextX, nextY, row, column) && visited[nextX][nextY] == 0 && board[nextX][nextY] == 'O'){
                bfs(board, visited, nextX, nextY);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int column = board[0].size();
        vector<vector<int>> visited(row, vector<int>(column, 0));

        //travel over border

        //left boundary
        for(int i = 0; i < row; i++){
            if(visited[i][0] == 0 && board[i][0] == 'O'){
                bfs(board, visited, i, 0);
            }
        }

        //right boundary
        for(int i = 0; i < row; i++){
            if(visited[i][column - 1] == 0 && board[i][column-1] == 'O'){
                bfs(board, visited, i, column - 1);
            }
        }

        //top row
        for(int i = 1; i < column - 1; i++){
            if(visited[0][i] == 0 && board[0][i] == 'O'){
                bfs(board, visited, 0, i);
            }   
        }

        //bottom row
        for(int i = 1; i < column - 1; i++){
            if(visited[row - 1][i] == 0 && board[row - 1][i] == 'O'){
                bfs(board, visited, row - 1, i);
            }   
        }


        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(board[i][j] == 'O' && visited[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }


    }
};