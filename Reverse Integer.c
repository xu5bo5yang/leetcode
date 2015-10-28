int reverse(int x) {
    double result = 0;
    char temp[12] = {0};
    int count = 0;
    int flag = 0;
    if (x == 0) return x;
    if (x < 0) {
        x = 0 - x;
        flag = 1;
    }
    while (x > 0) {
        temp[count] = '0' + x%10;
        x = x/10;
        count++;
    }
    for (int i=0; i<count; i++) {
        result = result * 10 + (temp[i] - '0');
    }
    if (result > INT_MAX) return 0;
    if (result == INT_MAX+1 && flag == 1) return INT_MIN;
    if (flag == 1) return 0-result;
    return result;
}