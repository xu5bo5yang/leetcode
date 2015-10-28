int lengthOfLongestSubstring(char* s) {
    if (s==NULL) return 0;
    int length = 0;
    int i, j;
    int pos[1000] = {0};
    int start = 0;
    int currentL = 0;
    for (i=0; i<strlen(s); i++) {
        if (pos[s[i]]>start) {
            length = length>currentL? length:currentL;
            start = pos[s[i]];
            currentL = i - pos[s[i]];
        }
        pos[s[i]] = i+1;
        currentL++;
    }
    return length>currentL? length:currentL;
}