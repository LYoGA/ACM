#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1000000000;
const int MAXN = 305;

char s[MAXN];
ll d[MAXN][MAXN];

ll dp(int i, int j) {
    if (i == j) return 1;
    if (s[i] != s[j]) return 0;

    ll &ans = d[i][j];
    if (ans >= 0)
        return ans;
    ans = 0;
    for (int k = i + 2; k <= j; k++)
        if (s[i] == s[k]) 
            ans = (ans + (ll)dp(i + 1, k - 1) * (ll)dp(k, j)) % MOD;
    return ans;
}

int main() {
    while (scanf("%s", s) != EOF) {
        memset(d, -1, sizeof(d));
        ll ans = dp(0, strlen(s) - 1); 
        printf("%lld\n", ans);
    }
    return 0;
}
