void swap(char* a, char* b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseString(char* s, int sSize){
    int left = 0;
    int right = sSize - 1;
    while (left <= right){
        swap(&s[left], &s[right]);
        left++;
        right--;
    }
}