#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
//typedef __int64 ll;

ll a, b, n, m;

struct mat{
    ll s[2][2];
    mat() {
        memset(s, 0, sizeof(s)); 
    }
    mat operator * (const mat& c) {
        mat ans;
        memset(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                ans.s[i][j] = (s[i][0] * c.s[0][j] + s[i][1] * c.s[1][j]) % m;
        return ans;
    }
    void put() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                printf("%lld ", s[i][j]);
            printf("\n");
        }
    }
}c;

void init() {
    c.s[0][0] = 2 * a;
    c.s[0][1] = b - a * a;
    c.s[1][0] = 1;
    c.s[1][1] = 0;
}

mat pow_mod(ll k) {
    if (k == 1)
        return c;
    mat a = pow_mod(k / 2);
    mat ans = a * a;
    if (k % 2)
        ans = ans * c;
    return ans;
}

int main() {
    while (scanf("%lld%lld%lld%lld", &a, &b, &n, &m) != EOF) {
        init();
        ll s1, s2;         
        s1 = (a * 2) % m;
        double t = pow(a + sqrt((double)b), 2);
        s2 = (ll)ceil(t) % m;
        if (n == 1)
            printf("%lld\n", s1);
        else if (n == 2)
            printf("%lld\n", s2);
        else {
            mat ans = pow_mod(n - 2); 
            ll a = (((ans.s[0][0] * s2 % m ) + m) % m + ((ans.s[0][1] * s1 % m ) + m)% m);
            printf("%lld\n", a % m);
        }
    } 
    return 0;
}

