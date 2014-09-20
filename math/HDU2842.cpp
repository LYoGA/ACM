#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

//typedef long long ll;
typedef __int64 ll;

const int MOD = 200907;

struct mat {
    ll s[3][3];
    mat () {
        memset(s, 0, sizeof(s)); 
    }
    mat operator * (const mat& c) {
        mat ans; 
        memset(ans.s, 0, sizeof(ans.s)); 
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]) % MOD;
        return ans;
    }
}tmp, c;

ll n;

void init() {
    tmp.s[0][0] = tmp.s[0][2] = tmp.s[1][0] = tmp.s[2][2] = c.s[1][0] = c.s[2][0] = 1;
    tmp.s[0][1] = c.s[0][0] = 2;
}

mat pow_mod(ll k) {
    if (k == 1)
        return tmp;
    mat a = pow_mod(k / 2);
    mat ans = a * a;
    if (k % 2)
        ans = ans * tmp;
    return ans;
}

int main() {
    init();
    while (scanf("%I64d", &n) && n) {
        if (n == 1 || n == 2) {
            printf("%I64d\n", n);
            continue;
        } 
        mat ans = pow_mod(n - 2); 
        ans = ans * c;
        printf("%I64d\n", ans.s[0][0]);
    }
    return 0;
}
