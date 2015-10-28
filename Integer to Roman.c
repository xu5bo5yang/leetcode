char* intToRoman(int num) {
    char* result = (char*)malloc(10*sizeof(char));
    int count = 0;
    int temp = num;
    temp = temp / 1000;
    switch (temp) {
        case 0:
            break;
        case 1:
            result[count++] = 'M';
            break;
        case 2:
            result[count++] = 'M';
            result[count++] = 'M';
            break;
        case 3:
            result[count++] = 'M';
            result[count++] = 'M';
            result[count++] = 'M';
            break;
        default:
            break;
    }
    num = num % 1000;
    temp = num;
    temp = temp / 100;
    switch (temp) {
        case 0:
            break;
        case 1:
            result[count++] = 'C';
            break;
        case 2:
            result[count++] = 'C';
            result[count++] = 'C';
            break;
        case 3:
            result[count++] = 'C';
            result[count++] = 'C';
            result[count++] = 'C';
            break;
        case 4:
            result[count++] = 'C';
            result[count++] = 'D';
            break;
        case 5:
            result[count++] = 'D';
            break;
        case 6:
            result[count++] = 'D';
            result[count++] = 'C';
            break;
        case 7:
            result[count++] = 'D';
            result[count++] = 'C';
            result[count++] = 'C';
            break;
        case 8:
            result[count++] = 'D';
            result[count++] = 'C';
            result[count++] = 'C';
            result[count++] = 'C';
            break;
        case 9:
            result[count++] = 'C';
            result[count++] = 'M';
            break;
        default:
            break;
    }
    num = num % 100;
    temp = num;
    temp = temp / 10;
    switch (temp) {
        case 0:
            break;
        case 1:
            result[count++] = 'X';
            break;
        case 2:
            result[count++] = 'X';
            result[count++] = 'X';
            break;
        case 3:
            result[count++] = 'X';
            result[count++] = 'X';
            result[count++] = 'X';
            break;
        case 4:
            result[count++] = 'X';
            result[count++] = 'L';
            break;
        case 5:
            result[count++] = 'L';
            break;
        case 6:
            result[count++] = 'L';
            result[count++] = 'X';
            break;
        case 7:
            result[count++] = 'L';
            result[count++] = 'X';
            result[count++] = 'X';
            break;
        case 8:
            result[count++] = 'L';
            result[count++] = 'X';
            result[count++] = 'X';
            result[count++] = 'X';
            break;
        case 9:
            result[count++] = 'X';
            result[count++] = 'C';
            break;
        default:
            break;
    }
    num = num % 10;
    switch (num) {
        case 0:
            break;
        case 1:
            result[count++] = 'I';
            break;
        case 2:
            result[count++] = 'I';
            result[count++] = 'I';
            break;
        case 3:
            result[count++] = 'I';
            result[count++] = 'I';
            result[count++] = 'I';
            break;
        case 4:
            result[count++] = 'I';
            result[count++] = 'V';
            break;
        case 5:
            result[count++] = 'V';
            break;
        case 6:
            result[count++] = 'V';
            result[count++] = 'I';
            break;
        case 7:
            result[count++] = 'V';
            result[count++] = 'I';
            result[count++] = 'I';
            break;
        case 8:
            result[count++] = 'V';
            result[count++] = 'I';
            result[count++] = 'I';
            result[count++] = 'I';
            break;
        case 9:
            result[count++] = 'I';
            result[count++] = 'X';
            break;
        default:
            break;
    }
    result[count] = '\0';
    return result;
}