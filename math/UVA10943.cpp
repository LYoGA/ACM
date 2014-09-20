#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1000000;
const int MAXN = 205;

int n, k;
ll c[MAXN][MAXN];

void init() {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < MAXN; i++) 
        c[i][0] = 1;
    for (int i = 1; i < MAXN; i++)
        for (int j = 1; j < MAXN; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
}

int main() {
    init();
    while (scanf("%d%d", &n, &k)) {
        if (n == 0 && k == 0) 
            break;
        printf("%lld\n", c[n + k - 1][k - 1]);
    }
    return 0;
}
