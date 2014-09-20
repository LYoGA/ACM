#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1234567891;
const int MAXN = 35;

struct mat{
    ll s[MAXN][MAXN];
    mat() {
        memset(s, 0, sizeof(s)); 
    }
    mat operator * (const mat& c) {
        mat ans; 
        memset(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < MAXN; i++) 
            for (int j = 0; j < MAXN; j++) 
                for (int k = 0; k < MAXN; k++) 
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]) % MOD;
        return ans;
    }
    void put() {
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++)  
                printf("%lld ", s[i][j]);
            printf("\n");
        }
    }
}c;

ll n;
int k;

void init() {
    memset(c.s, 0, sizeof(c.s));
    c.s[0][0] = 1;  
    c.s[k][0] = 1;  
    for (int i = 1; i < k + 1; i++) {  
        c.s[i][i] = i;  
        if (i > 1) 
            c.s[i - 1][i] = k - i + 1;  
    }  
}

mat pow_mod(ll n) {
    if (n == 1)
        return c;
    mat a = pow_mod(n / 2);
    mat ans = a * a;
    if (n % 2)
        ans = ans * c;
    return ans;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%lld%d", &n, &k);    
        init();
        mat ans = pow_mod(n);
        printf("%lld\n", k * ans.s[1][0] % MOD);
    }
    return 0;
}
