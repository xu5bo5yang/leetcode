char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    int i = 0;
    int j = 0;
    while (strs[0][j] != '\0') {
        i = 0;
        while (i < strsSize && strs[i][j] == strs[0][j]) {
            i++;
        }
        if (i < strsSize) {
            break;
        }
        j++;
    }
    strs[0][j] = '\0';
    return strs[0];
}