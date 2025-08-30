class Solution {
private:
    int getBoxId(int row, int col){
        return (3*(row/3)) + (col / 3);
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> col_set(9);
        vector<unordered_set<char>> row_set(9);    
        vector<unordered_set<char>> box_set(9);

        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                char elem = board[i][j];
                if(elem != '.'){
                   int boxId = getBoxId(i, j);

                    if(row_set[i].find(elem) != row_set[i].end()
                    || col_set[j].find(elem) != col_set[j].end()
                    || box_set[boxId].find(elem) != box_set[boxId].end()
                    ) { 
                        return false;   
                    }

                    row_set[i].insert(elem);
                    col_set[j].insert(elem);
                    box_set[boxId].insert(elem); 
                }
                
            }
        }

        return true;
    }
};