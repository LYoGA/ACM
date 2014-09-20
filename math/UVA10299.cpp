#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
using namespace std;
ll n, p, k;
int m;

struct mat{
    ll s[2][2];
    mat(ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        s[0][0] = a; 
        s[0][1] = b; 
        s[1][0] = c; 
        s[1][1] = d; 
    }
}c(1, 1, 1, 0), tmp(1, 0, 0, 1);

mat operator * (const mat& a, const mat& b) {
    mat Mat;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            Mat.s[i][j] = (a.s[i][0] * b.s[0][j] + a.s[i][1] * b.s[1][j]) % p;
    return Mat; 
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
    while (scanf("%lld%d", &n, &m) != EOF) {
        p = pow(2, m); 
        if (n) {
            mat ans = pow_mod(n - 1); 
            k = ans.s[0][0];
        }  
        else
            k = 0;
        printf("%lld\n", k);
    } 
    return 0;
}

