#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 510;
const int MOD = 1000007;

int C[MAXN][MAXN];
int n, m, k;

void init() {
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for (int i = 0; i < MAXN; i++) {
        C[i][0] = C[i][i] = 1; 
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
}

int main() {
    init();
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &n, &m, &k); 
        int sum = 0; 
        for (int S = 0; S < 16; S++) {
            int b = 0, r = n, c = m;  
            for (int i = 0; i < 4; i++) {
                if (S & (1 << i)) {
                    if (i % 2)
                        r--;
                    else
                        c--;
                    b++;
                } 
            }
            if (b & 1)
                sum = (sum + MOD - C[r * c][k]) % MOD;
            else
                sum = (sum + C[r * c][k]) % MOD;
        }
        printf("Case %d: %d\n", t++, sum);
    }
    return 0;
}
