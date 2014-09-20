#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;

ll sovle(ll k) {
    if (n == 0) 
        return 1;
    if (n == 1) 
        return 2;
    ll ans = 2;
    for (ll i = 2; i <= k; i++)
        ans += i;
    return ans;
}

int main() {
    while (scanf("%lld", &n) && (n >= 0)) {
        ll ans = sovle(n); 
        printf("%lld\n", ans);
    }
    return 0;
}
