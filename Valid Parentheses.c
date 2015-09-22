bool isValid(char* s) {
    if (s == NULL) return true;
    int* parent;
    int length = 0;
    int i = 0;
    int j = 1;
    while (s[length] != '\0') {
        length++;
    }
    parent = (int*)malloc((length+1)*sizeof(int));
    for (i=0; i<=length; i++) parent[i] = 0;
    i = 0;
    while (i < length) {
        switch (s[i]) {
            case '(':
                parent[j] = 1;
                j++;
                i++;
                break;
            case '{':
                parent[j] = 2;
                j++;
                i++;
                break;
            case '[':
                parent[j] = 3;
                j++;
                i++;
                break;
            case ')':
                if (parent[j-1] != 1) return false;
                else {
                    j--;
                    parent[j] = 0;
                    i++;
                    break;
                }
            case '}':
                if (parent[j-1] != 2) return false;
                else {
                    j--;
                    parent[j] = 0;
                    i++;
                    break;
                }
            case ']':
                if (parent[j-1] != 3) return false;
                else {
                    j--;
                    parent[j] = 0;
                    i++;
                    break;
                }
            default:
                i++;
                break;
        }
    }
    for (i=0; i<=length; i++) {
        if (parent[i] > 0) return false;
    }
    return true;
}