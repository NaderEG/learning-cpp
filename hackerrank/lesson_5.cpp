#include <stdio.h>

void update(int *a,int *b) {
    int num1 = *a;    
    int num2 = *b;
    
    *a = num1 + num2;
    
    *b = num1-num2;
    if (*b < 0) {
        *b = *b * -1;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}