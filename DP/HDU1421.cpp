#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 2005;

int dp[MAXN][MAXN], a[MAXN];

int Pow(int a) {
    return a * a;
}

int main () {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++)   
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * 2 <= i; j++) {
                if (i == j * 2) 
                    dp[i][j] = dp[i - 2][j - 1] + Pow(a[i - 1] - a[i]);
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + Pow(a[i] - a[i - 1])); 
            }  
        }
        printf("%d\n", dp[n][k]); 
    }
    return 0;
}
