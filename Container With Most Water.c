int maxArea(int* height, int heightSize) {
    int *left = height;
    int *right = height + heightSize - 1;
    int h = 0;
    int result = 0;
    int water = 0;
    while (left < right) {
        h = *left < *right? *left:*right;
        water = h * (right - left);
        result = result > water? result:water;
        while(*left<=h && left < height+heightSize) left++;
        while(*right<=h && right > height) right--;
    }
    return result;
}