void reverseWords(char *s) {
    if (s==NULL) return;
    char temp;
    int i = 0;
    int j, k;
    int length = strlen(s);
    int count = 0;
    int flag = 1;
    for (i=0; i<length; i++) {
        if (s[i]!=' ') {
            s[count] = s[i];
            count++;
            flag = 0;
        }
        else {
            if (flag == 0) {
                s[count] = s[i];
                count++;
                flag = 1;
            }
        }
    }
    if(s[count-1]==' ' && count>0) s[count-1] = '\0';
    else s[count] = '\0';
    
    length = strlen(s);
    for (i=0, j=length-1; i<j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    j = 0;
    k = 0;
    for (i=0; i<length; i++) {
        if (s[i]==' ' || s[i]=='\0' || i==length-1) {
            if (i==length-1) {
                for (k=i; j<k; j++, k--) {
                    temp = s[j];
                    s[j] = s[k];
                    s[k] = temp;
                }
            }
            else {
                for (k=i-1; j<k; j++, k--) {
                    temp = s[j];
                    s[j] = s[k];
                    s[k] = temp;
                }
            }
            j = i+1;
        }
    }
}