char* convertToTitle(int n) {
    char result[10] = {0};
    char answer[10] = {0};
    int i = 0;
    int temp = 0;
    int length = 0;
    while (n > 0) {
        temp = n % 26 - 1;
        if (temp == -1) temp = 25;
        result[i] = 'A' + temp;
        i++;
        if (temp == 25) n--;
        n = n / 26;
        length++;
    }
    for (i = 0; i < length; i++) {
        answer[i] = result[length-i-1];
    }
    return answer;
}