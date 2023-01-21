#include<stdio.h>
#include<stdlib.h>

int comparator(const void* i, const void* j) {
    return *((int*)i) - *((int*)j);
}

int main () {
    int a[5] = {1,2,6,4,5};

    qsort(a, 5, sizeof(int), comparator);

    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}