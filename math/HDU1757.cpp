#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef __int64 ll;

const int N = 10;

ll k, m;

struct mat{
    ll s[N][N];
    mat() {
        sizeof(s, 0, sizeof(s));
    }

    mat operator * (const mat& c) {
        mat ans; 
        memset(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]) % m;
        return ans;
    }
};

mat state, tmp;

void init() {
    for (int i = 0; i < 10; i++)
        tmp.s[i][0] = 9 - i;
    for (int i = 0; i < 10; i++) 
        scanf("%I64d", &state.s[0][i]);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (i - 1 == j)
                state.s[i][j] = 1;
}

mat pow_mod(ll k) {
    if (k == 1)
        return state;
    mat a = pow_mod(k / 2);
    mat ans = a * a;
    if (k % 2 == 1)
        ans = ans * state;
    return ans;
}

int main() {
    while (scanf("%I64d%I64d", &k, &m) != EOF) {
        if (k < 10) 
            printf("%I64d\n", k % m); 
        else {
            init();
            mat ans = pow_mod(k - 9);
            ans = ans * tmp;
            printf("%I64d\n", ans.s[0][0]);
        } 
    }
    return 0;
}
