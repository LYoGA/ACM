#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
using namespace std;

ll n, b;

struct mat{
    ll s[2][2];
    mat(ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        s[0][0] = a; 
        s[0][1] = b; 
        s[1][0] = c; 
        s[1][1] = d; 
    }
}c(1, 1, 1, 0), tmp(1, 0, 0, 1);

mat operator * (const mat& p, const mat& q) {
    mat state;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            state.s[i][j] = (p.s[i][0] * q.s[0][j] + p.s[i][1] * q.s[1][j]) % b;
    return state;
}

mat pow_mod(ll k) {
    if (k == 0)
        return tmp;
    else if (k == 1)
        return c;
    mat a = pow_mod(k / 2);
    a = a * a;
    if (k % 2)
        a = a * c;
    return a;
}

int main() {
    int t = 1;
    while (scanf("%lld %lld", &n, &b) && (n || b)) {
        mat temp = pow_mod(n); 
        ll ans = temp.s[0][0];
        printf("Case %d: %lld %lld %lld\n", t++, n, b, (2 * ans - 1 + b) % b); 
    }    
    return 0;
}
