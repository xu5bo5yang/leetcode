bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    if (n == 1) return true;
    while (n == n/2*2) {
        n = n / 2;
    }
    if (n == 1) return true;
    else return false;
}