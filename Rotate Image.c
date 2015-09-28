void swap(int* x, int* y) {
    int temp;
    temp = *x; 
    *x = *y;
    *y = temp;
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int n = matrixRowSize;
        // 1) reverse each row
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n/2; j++ ) {
                swap(&matrix[i][j], &matrix[i][n - 1 - j]);
            }
        }
        // 2) swap diagnoal elements
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                swap(&matrix[i][j], &matrix[n - 1 - j][n - 1 - i]);
                if ( i == n - 1 - j ) {
                    break;
                }
            }
        }
}