int lengthOfLastWord(char* s) {
    int length = 0;
    int pre = 0;
    int i;
    if (s == NULL) return 0;
    for (i=0; s[i]!='\0'; i++) {
        if (s[i] == ' ' && s[i-1] != ' ') {
            length = i - pre;
        }
        else if (s[i] != ' ' && s[i-1] == ' ') {
            pre = i;
        }
    }
    if (s[i-1] != ' ') length = i - pre;
    return length;
}