#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef __int64 ll;
//typedef long long ll;

const int MOD = 1000000000;

ll n;

ll pow_mod(ll k) {
    if (k == 1)
        return n % MOD;
    ll a = pow_mod(k / 2);
    ll ans = a * a % MOD; 
    if (k % 2 == 1)
        ans = ans * n % MOD;
    return ans;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {               
        scanf("%I64d", &n);
        ll ans = pow_mod(n);
        while (ans > 10) {
            ans %= 10; 
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
