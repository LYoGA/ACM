#include <iostream>
#include <cstdio>
#include <cstring> 
#include <algorithm>
#define N 55
#define INF 1<<30

using namespace std;

int d[N][N], arr[N];
int n, m;

int dp(int a, int b) {
    if (d[a][b]) return d[a][b];
    if (a == b - 1) return 0;
    d[a][b] = INF;
    for (int i = a + 1; i < b; i++)
        if (dp(a, i) + dp(i, b) < d[a][b])
            d[a][b] = d[a][i] + d[i][b];
    return d[a][b] += arr[b] - arr[a];
}

int main () {
    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &m);
        memset(d, 0, sizeof(d));
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= m; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr + m + 1); 
        arr[m + 1] = n;
        printf("The minimum cutting is %d.\n", dp(0, m + 1));
    }   
    return 0;
}
