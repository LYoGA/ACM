#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

//typedef long long ll;
typedef __int64 ll;

const int N = 2;

struct mat{
    ll s[N][N];
    mat(ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        s[0][0] = a;
        s[0][1] = b;
        s[1][0] = c;
        s[1][1] = d;
    } 
    mat operator * (const mat& c) { 
        mat ans; 
        memset(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans.s[i][j] = (s[i][0] * c.s[0][j] + s[i][1] * c.s[1][j]);
        return ans;
    }
    mat operator % (int mod) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                s[i][j] %= mod; 
        return *this;
    }
    mat operator + (const mat& c) {
        mat ans; 
        memset(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans.s[i][j] = s[i][j] + c.s[i][j];
        return ans; 
    }
    void put() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("%I64d ", s[i][j]);
            printf("\n");
        } 
    }
}c(1, 1, 1, 0), tmp(1, 0, 0, 1);

ll k, b, n, M;

mat pow_mod(int n, mat c) {
    if (n == 0)
        return tmp;
    if (n == 1)
        return c;
    mat a = pow_mod(n / 2, c);
    mat ans = a * a % M;
    if (n % 2)
        ans = ans * c % M;
    return ans;
}

mat sum(int n, mat a) {
    if (n == 1)
        return a;
    if (n & 1)
        return (pow_mod(n, a) + sum(n - 1, a)) % M; 
    else
        return (((pow_mod(n / 2, a) + tmp) % M) * sum(n / 2, a) % M);
}

int main() {
    while (scanf("%I64d%I64d%I64d%I64d", &k, &b, &n, &M) != EOF) {
        mat A = pow_mod(b, c); 
        mat B = pow_mod(k, c); 
        mat C = sum(n - 1, B) + tmp;
        C = C * A;
        printf("%I64d\n", C.s[0][1] % M);
    }
    return 0;
}
