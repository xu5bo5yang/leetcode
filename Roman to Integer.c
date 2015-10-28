#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int romanToInt(char* s) {
    char cur = '0';
    char pre = '0';
    int i, j;
    int result = 0;
    if (s == NULL) return 0;
    
    for (i=strlen(s)-1; i>=0; i--) {
        cur = s[i];
        switch(s[i]) {
            case 'I':
                if (pre == 'V' || pre == 'X') result -= I;
                else result += I;
                break;
            case 'V':
                result += V;
                break;
            case 'X':
                if (pre == 'L' || pre == 'C') result -= X;
                else result += X;
                break;
            case 'L':
                result += L;
                break;
            case 'C':
                if (pre == 'D' || pre == 'M') result -= C;
                else result += C;
                break;
            case 'D':
                result += D;
                break;
            case 'M':
                result += M;
                break;
        }
        pre = s[i];
    }
    return result;
}