char* getHint(char* secret, char* guess) {
    int hashS[10] = {0};
    int hashG[10] = {0};
    int len = strlen(secret);
    int i;
    int a = 0;
    int b = 0;
    for (i=0; i<len; i++) {
        if (secret[i] == guess[i]) {
            a++;
        }
        else {
            hashS[secret[i]-'0']++;
            hashG[guess[i]-'0']++;
        }
    }
    for (i=0; i<10; i++) {
        if (hashS[i] > 0 && hashG[i] > 0) {
            b += (hashS[i] < hashG[i] ? hashS[i]:hashG[i]);
        }
    }
    char* result = (char*)malloc(20*sizeof(char));
    sprintf(result, "%dA%dB\0", a, b);
    return result;
}