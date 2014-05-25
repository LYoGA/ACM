#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10005
using namespace std;

int arr[N];

int cmp(int a, int b) {
    return a < b;
}

int main() {
    int n, flag = 0;
    while (scanf("%d", &n) && n) {
        if (flag)
            printf("\n");
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]);
        sort(arr, arr + n, cmp); 
        int max = 1, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) 
                cnt++; 
            else
                cnt = 1;
            if (cnt > max) 
                max = cnt;
        }
        printf("%d\n", max);
        for (int i = 0; i < max; i++) {
            for (int j = i; j < n; j = j + max) {
                printf("%d", arr[j]); 
                if (j + max < n) 
                    printf(" "); 
            } 
            printf("\n");
        }

    }
    return 0;
}
