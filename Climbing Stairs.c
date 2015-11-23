int climbStairs(int n) {
    if (n <= 2) return n;
    int i;
    int pre = 2;
    int prepre = 1;
    int result = 0;
    for (i = 3; i <= n; i++) {
        result = pre + prepre;
        prepre = pre;
        pre = result;
    }
    return result;
}