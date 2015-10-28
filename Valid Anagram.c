bool isAnagram(char* s, char* t) {
    int hash[100] = {0};
    int i;
    if (strlen(s)!=strlen(t)) return false;
    for (i=0; i<strlen(s); i++) {
        hash[s[i]-'a']++;
    }
    for (i=0; i<strlen(t); i++) {
        hash[t[i]-'a']--;
    }
    for (i=0; i<100; i++) {
        if (hash[i]!=0) return false;
    }
    return true;
}