int myAtoi(char* str) {
    double result = 0;
    int flag = 0;
    int nflag = 0;
    if (str==NULL) return 0;
    while(*str != '\0') {
        if (*str==' ') {
            if (flag!=0) break;
            str++;
        }
        else if (*str=='+' && flag==0) {
            str++;
            flag = 1;
        }
        else if (*str=='-' && flag==0) {
            str++;
            flag = 1;
            nflag = 1;
        }
        else if ((*str-'0') <=9 && (*str-'0') >=0) {
            result = result*10 + *str - '0';
            str++;
            flag = 1;
        }
        else break;
    }
    if (nflag == 1) {
        if (result > INT_MAX) result = INT_MAX+1;
        result = 0-result;
    }
    else {
        if (result > INT_MAX) result = INT_MAX;
    }
    return result;
}