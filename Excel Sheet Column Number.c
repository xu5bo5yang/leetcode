int titleToNumber(char* s) {
    if (s == NULL) return 0;
    int i = 0;
    int result = 0;
    while (s[i] != '\0') {
        result = result * 26 + s[i] - 'A' + 1;
        i++;
    }
    return result;
}