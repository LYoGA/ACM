#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 105;

double dp[MAXN][MAXN];
int k, n;

void init() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= k; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= k; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
            else if (j == k)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; 
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1] + dp[i - 1][j - 1];
        }
}

int main() {
    while (scanf("%d%d", &k, &n) != EOF) {
        init();
        double ans = 0;
        for (int i = 0; i <= k; i++)         
            ans += dp[n][i]; 
        double tmp = pow(k + 1, (double)n);
        double p = ans / tmp * 100;
        printf("%.5lf\n", p);
    }    
    return 0;
}
