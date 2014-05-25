#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 100005;
const int N = 11;

int dp[MAXN][N], a[MAXN][N];

int max(int x, int y, int z) {
    int temp;
    if (x >= y) 
        temp = x;
    else
        temp = y;
    if (temp < z) 
        temp = z;
    return temp;
}

int main () {
    int n;
    while (scanf("%d", &n) && n) {
        int x, t, temp;
        temp = -1;
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &t); 
            a[t][x]++; 
            if (temp < t)
                temp = t;
        }
        for (int i = temp; i > 0; i--) {
            for (int j = 0; j < N; j++) 
                if (i == temp)
                    dp[i][j] = a[i][j];
                else if (j == 0)
                    dp[i][j] = max(0, dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j]; 
                else if (j == N - 1)
                    dp[i][j] = max(dp[i + 1][j - 1], dp[i + 1][j], 0) + a[i][j];
                else
                    dp[i][j] = max(dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j]; 
        }
        printf("%d\n", max(dp[1][4], dp[1][5], dp[1][6]));
    }
    return 0;
}
