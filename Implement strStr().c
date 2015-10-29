void table(int* t, int length, char* needle) {
    t[0] = -1;
    t[1] = 0;
    int pos = 2;
    int next = 0;
    while (pos < length) {
        if (needle[next] == needle[pos-1]) {
            next++;
            t[pos] = next;
            pos++;
        }
        else if (next > 0) {
            next = t[next];
        }
        else {
            t[pos] = 0;
            pos++;
        }
    }
}

int strStr(char* haystack, char* needle) {
    if (needle==NULL) return 0;
    if (haystack==NULL) return -1;
    if (strlen(needle) < 1) return 0;
    int* t;
    t = (int*)malloc(strlen(needle)*sizeof(int));
    table(t, strlen(needle), needle);
    int m = 0;
    int i = 0;
    while ((m+i) < strlen(haystack)) {
        if (needle[i] == haystack[m + i]) {
            if (i == strlen(needle)-1) {
                return m;
            }
            i++;
        }
        else {
            if (t[i] > -1) {
                m += i - t[i];
                i = t[i];
            }
            else {
                i = 0;
                m++;
            }
        }
    }
    return -1;
}