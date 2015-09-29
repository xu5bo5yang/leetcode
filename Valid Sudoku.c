bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int checkRow[9] = {}, checkCol[9] = {}, checkSqr[9] = {};
    int checkBit;
    int row, col, sqr;
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            if(board[row][col] != '.'){
                checkBit = 1 << (board[row][col] - '1');
                sqr = row/3 + (col/3)*3;
                if(checkRow[row] & checkBit || checkCol[col] & checkBit || checkSqr[sqr] & checkBit) return false;
                checkRow[row] |= checkBit;
                checkCol[col] |= checkBit;
                checkSqr[sqr] |= checkBit;
            }
        } 
    }
    return true;
}