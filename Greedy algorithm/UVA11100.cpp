#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1000000;
const int MAXN = 10005;

int n;
int arr[MAXN], num[MAXN];

int main() {
    int t = 0;
    while (scanf("%d", &n) && n) {
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) { 
            scanf("%d", &arr[i]); 
            num[arr[i]]++; 
        }
        arr[n] = INF;
        int Max = 0, cnt = 0, temp = 0;
        for (int i = 0; i < MAXN; i++) {
            if (num[i] > cnt) {
                cnt = num[i]; 
                temp = i;
            } 
        }
        Max = num[temp];
        if (t) 
            printf("\n");  
        t = 1; 
        printf("%d\n", Max);

        sort(arr, arr + n); 
        for (int i = 0; i < Max; i++) {
            printf("%d", arr[i]);
            for (int j = i + Max; j < n; j += Max) {
                    printf(" %d", arr[j]);  
            }
            printf("\n"); 
        }
    }
    return 0;
}
