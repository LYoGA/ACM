#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;

const int MOD = 1000000007;

using namespace std;

ll n;

/*ll pow_mod(ll k) {
    if (k == 0)
        return 1;
    if (k == 1)
        return 2;
    ll a = pow_mod(k / 2);
    ll ans = a * a % MOD;
    if (k % 2)
        ans = ans * 2 % MOD;
    return ans;
}*/

ll pow_mod(ll k) {
    ll ans = 1;
    ll temp = 2; 
    while (k) {
        if (k & 1)   
            ans = ans * temp % MOD;        
        k >>= 1; 
        temp = (temp * temp) % MOD;
    }
    return ans;
}

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%lld", &n);   
        ll ans = pow_mod(n - 1);          
        ans = ans * n % MOD; 
        printf("Case #%d: %lld\n", t++, ans);
    }
    return 0;
}
