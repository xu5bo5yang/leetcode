bool isIsomorphic(char* s, char* t) {
    char hashs[128] = {0};
    char hasht[128] = {0};
    for (int i=0; s[i]!='\0'; i++) {
        char ss = s[i];
        char tt = t[i];
        if (hashs[ss] == 0 && hasht[tt] == 0) {
            hashs[ss] = tt;
            hasht[tt] = ss;
        }
        else if (hashs[ss] != tt || hasht[tt] != ss) return false;
    }
    return true;
}