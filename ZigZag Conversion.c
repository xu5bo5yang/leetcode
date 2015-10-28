char* convert(char* s, int numRows) {
    int length = strlen(s);
    int i, j;
    int rIndex = 0;
    if (numRows == 1 || numRows > length) return s;
    char* result = (char*)malloc((length+1)*sizeof(char));
    for (i=0; i<numRows; i++) {
        for (j=i; j<length; j+=2*numRows-2) {
            result[rIndex] = s[j];
            rIndex++;
            if (i!=0 && i!=numRows-1 && j+2*(numRows-i-1)<length) {
                result[rIndex] = s[j+2*(numRows-i-1)];
                rIndex++;
            }
        }
    }
    result[length] = '\0';
    return result;
}