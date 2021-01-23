static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num){ // teh main important function
        /*
        for(int i = 0; i < 9; i++) {
            if(board[i][col] != '.' && board[i][col] == c) return false; //check row
            if(board[row][i] != '.' && board[row][i] == c) return false; //check column
            if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
        }*/
            
        int blkrow = (row / 3) * 3, blkcol = (col / 3) * 3; // Block no. is i/3, first element is i/3*3
        for (int i = 0; i < 9; i++)
            if (board[i][col] == num || board[row][i] == num || 
                    board[blkrow + i / 3][blkcol + i % 3] == num)
                return false;
        return true;
    }
    
    // continue from the last, row,col
    bool doSolve(vector<vector<char>>& board, int row, int col){
        for (int i = row; i < 9; i++, col = 0) { // note: must reset col here!, process parts of input at a time
            for (int j = col; j < 9; j++) {
                if (board[i][j] != '.') continue;
                for (char num = '1'; num <= '9'; num++) { // explore possibilities
                    if (isValid(board, i, j, num)) {
                        board[i][j] = num;
                        if (doSolve(board, i, j + 1)) // if decision ok
                            return true;
                        board[i][j] = '.'; // undo decision
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        doSolve(board,0,0);
    }
};
