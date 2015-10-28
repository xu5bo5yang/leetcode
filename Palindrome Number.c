bool isPalindrome(int x) {
    int result = 0;
    int temp = x;
    
    if (x < 0) return false;
    if (x < 10) return true;
    
    while(temp > 0) {
        result = result*10 + temp%10;
        temp = temp / 10;
    }
    
    return result==x;
}