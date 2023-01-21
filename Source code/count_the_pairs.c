#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return 1;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    int N, K, count;
    count = 0;
    scanf("%d", &N);
    scanf("%d", &K);

    int input_arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &input_arr[i]);
    }

    count = 0;
    
    qsort(input_arr, N, sizeof(int), compare);
    
    int l = 0;
    int r = 0;
    while(r < N)
    {
        if(input_arr[r] - input_arr[l] == K)
        {
              count++;
              l++;
              r++;
        }
         else if(input_arr[r] - input_arr[l] > K)
              l++;
         else
              r++;
    }  

    printf("%d\n", count);

    return count;
}