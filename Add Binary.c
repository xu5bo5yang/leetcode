char* addBinary(char* a, char* b) {
    int length;
    length = strlen(a) > strlen(b) ? strlen(a):strlen(b);
    length++;
    int i;
    int flag = 0;
    if (strlen(a) > strlen(b)) {
        char* temp = a;
        a = b;
        b = temp;
    }
    char* ar = (char*)malloc(strlen(a)*sizeof(char));
    for (i=0; i<strlen(a); i++) {
        ar[i] = a[strlen(a)-i-1];
    }
    char* br = (char*)malloc(strlen(b)*sizeof(char));
    for (i=0; i<strlen(b); i++) {
        br[i] = b[strlen(b)-i-1];
    }
    printf("ar: %s\nbr: %s\n", ar, br);
    char* result = (char*)malloc(length*sizeof(char));
    for (i=0; i<strlen(a); i++) {
        if (ar[i] - '0' + br[i] - '0' + flag >= 2) {
            result[i] = '0' + ar[i] - '0' + br[i] - '0' + flag - 2;
            flag = 1;
            printf("%d: %c + %c + %d = %c\n", i, ar[i], br[i], flag, result[i]);
        }
        else {
            result[i] = '0' + ar[i] - '0' + br[i] - '0' + flag;
            flag = 0;
            printf("%d: %c + %c + %d = %c\n", i, ar[i], br[i], flag, result[i]);
        }
    }
    for (i=strlen(a); i<strlen(b); i++) {
        if (br[i] - '0' + flag >= 2) {
            result[i] = '0' + br[i] - '0' + flag - 2;
            flag = 1;
        }
        else {
            result[i] = '0' + br[i] - '0' + flag;
            flag = 0;
        }
    }
    printf("%d\n", i);
    if (flag == 1) {
        result[i] = '1';
        length++;
    }
    char* answer = (char*)malloc(length*sizeof(char));
    for (i=0; i<length-1; i++) {
        answer[i] = result[length-i-2];
    }
    answer[i] = '\0';
    return answer;
}