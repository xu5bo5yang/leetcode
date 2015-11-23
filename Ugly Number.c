bool isUgly(int num) {
    if (num <= 0) return false;
    while(num == num/2*2) {
        num = num/2;
    }
    while(num == num/3*3) {
        num = num/3;
    }
    while(num == num/5*5) {
        num = num/5;
    }
    if (num == 1) return true;
    return false;
}