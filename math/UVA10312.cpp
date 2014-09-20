#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 30;

ll Catalan[MAXN], dp[MAXN][2];
int n;

void init() {
    memset(Catalan, 0, sizeof(Catalan));
    Catalan[1] = Catalan[2] = 1;
    for (int i = 3; i < MAXN; i++)
        Catalan[i] = Catalan[i - 1] * (4 * i - 6) / i; 
}

ll dfs(int n, int m) {
    ll& ans = dp[n][m];
    if (ans != 0)
        return ans;
    if (n <= 1)
        return 1;
    ans = 0;
    for (int i = 1; i < n + m; i++)
        ans += dfs(i, 1) * dfs(n - i, 0);
    return ans;
}

int main() {
    init();
    while (scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof(dp)); 
        printf("%lld\n", dfs(n, 0) - Catalan[n]);
    }
    return 0;
}
