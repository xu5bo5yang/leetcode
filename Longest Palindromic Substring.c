char* longestPalindrome(char* s) {
    int longest = 1, length = strlen(s);
    char *start = s, *center = s;

    while (center + longest / 2 < s + length) {

        char* c = center;
        char* end = center + 1;
        // count # of chars in the center
        // eg. in ...abbbba..., there are 4 b's in the center
        while(*c == *end) { 
            end++;
        } 
        center = end;
        while(c > s && *(c-1) == *end) {
            c--;
            end++;
        }
        
        if((end-c) > longest) { 
            longest = end - c; 
            start = c;
        }
    }

    char *result = (char*)malloc((longest+1)*sizeof(char));
    for(int i = 0; i < longest; i++) {
        result[i] = start[i];
    }
    result[longest] = '\0';
    return result;
}