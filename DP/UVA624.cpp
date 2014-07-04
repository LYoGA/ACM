#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
const int N = 25;

int dp[MAXN], arr[N], vis[N][MAXN]; 
int n, m; 

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < m; i++)  
            scanf("%d",&arr[i]);
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        for (int i = m - 1; i >= 0; i--)
            for (int j = n; j >= arr[i]; j--) 
                if (dp[j] <= dp[j - arr[i]] + arr[i]) {
                    dp[j] = dp[j - arr[i]] + arr[i];
                    vis[i][j] = 1;
                }  
        for (int i = 0, j = n; i < m; i++)
            if (vis[i][j]) {
                printf("%d ", arr[i]); 
                j -= arr[i];
            }
        printf("sum:%d\n", dp[n]);
    }
    return 0;
}
