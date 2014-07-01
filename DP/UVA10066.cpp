#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int arr1[MAXN], arr2[MAXN], dp[MAXN][MAXN];
int n, m, t = 1;

int LCSL(int n, int m) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (arr1[i - 1] == arr2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        
        }
    return dp[n][m];
}

int main() {
    while (scanf("%d %d", &n, &m) && n && m) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr1[i]); 
        for (int i = 0; i < m; i++) 
            scanf("%d", &arr2[i]); 
        memset(dp, 0, sizeof(dp));
        int ans = LCSL(n, m);
        printf("Twin Towers #%d\n", t++);
        printf("Number of Tiles : %d\n\n", ans);
    }
    return 0;
}
