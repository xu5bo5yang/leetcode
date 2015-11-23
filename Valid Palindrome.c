bool isEqual(char a, char b) {
    if (a == b || (a - b) == 32 || (b - a) == 32) return true;
    return false;
}

bool isAlnum(char a) {
    if (a >= '0' && a <= '9') return true;
    if (a >= 'a' && a <= 'z') return true;
    if (a >= 'A' && a <= 'Z') return true;
    return false;
}

bool isPalindrome(char* s) {
    if (s == NULL) return true;
    int i, j;
    int len = strlen(s);
    
    for (i=0, j=len-1; i<j; i++,j--) {
        while (!isAlnum(s[i]) && i < j) i++;
        while (!isAlnum(s[j]) && i < j) j--;
        if (!isEqual(s[i], s[j])) return false;
    }
    return true;
}