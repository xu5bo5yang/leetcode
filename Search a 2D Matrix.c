bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrixRowSize == 0 || matrixColSize == 0) return false;
    if (matrix == NULL) return false;
    int i, j;
    for (i=0; i<matrixRowSize; i++) {
        if (target == matrix[i][0]) return true;
        if (target < matrix[i][0]) {
            break;
        }
    }
    i--;
    if (i < 0) return false;
    for (j=0; j<matrixColSize; j++) {
        if (target == matrix[i][j]) return true;
    }
    return false;
}