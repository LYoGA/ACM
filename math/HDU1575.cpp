#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

//typedef long long ll;
typedef __int64 ll;

const int MOD = 9973;
const int N = 15;

ll k;
int n;

struct mat{
    int s[N][N];    
    mat() {
        memset(s, 0, sizeof(s)); 
    }
    mat operator * (const mat& c) {
        mat ans; 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++) 
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]) % MOD;
        return ans;
    }
};

mat state;

mat pow_mod(ll k) {
    if (k == 1)
        return state;
    mat a = pow_mod(k / 2);
    mat ans = a * a;
    if (k % 2)
        ans = ans * state;
    return ans;
}

int main() {
    int cas; 
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%I64d", &n, &k);    
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &state.s[i][j]);
        mat c = pow_mod(k);
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j)
                    ans += c.s[i][j];
        printf("%d\n", ans % MOD);
    }
    return 0;
}
