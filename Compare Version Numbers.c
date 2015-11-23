int compareVersion(char* version1, char* version2) {
    if (version1 == NULL || version2 == NULL) return 0;
    if (version1 == version2) return 0;
    int v1 = 0, v2 = 0;
    int i1, i2;
    for (i1=0, i2=0; version1[i1]!='\0' || version2[i2]!='\0'; ) {
        while (version1[i1] != '\0' && version1[i1] != '.') {
            v1 = v1*10 + version1[i1]-'0';
            i1++;
        }
        while (version2[i2] != '\0' && version2[i2] != '.') {
            v2 = v2*10 + version2[i2]-'0';
            i2++;
        }
        if (v1 > v2) return 1;
        else if (v1 < v2) return -1;
        else {
            v1 = v2 = 0;
            if (version1[i1] == '.') i1++;
            if (version2[i2] == '.') i2++;
        }
    }
}