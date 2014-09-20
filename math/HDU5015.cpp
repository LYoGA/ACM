#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 15;
const int MOD = 10000007;

struct mat{
    ll s[N][N];
    int l;
    mat(int o) {
        l = o;
        memset(s, 0, sizeof(s)); 
    }
    void init() {
        s[0][0] = s[1][0] = 1; 
        s[1][1] = 10;
        for (int i = 2; i < l; i++)
            for (int j = 1; j <= i; j++)
                s[i][j] = 1;
    }
    mat operator * (const mat& c) {
        mat ans(l); 
        for (int i = 0; i < l; i++) 
            for (int j = 0; j < l; j++)
                for (int k = 0; k < l; k++)
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]) % MOD;
        return ans;
    }
};

int n, m;

mat Pow(mat c, int k) {
    mat ans = c;
    k--;
    while (k) {
        if (k & 1) 
            ans = ans * c;
        c = c * c;
        k >>= 1;
    }
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        mat a(n + 2);  
        a.s[0][0] = 3;
        a.s[1][0] = 233;
        for (int i = 2; i <= n + 1; i++)
            scanf("%I64d", &a.s[i][0]);
        mat tmp(n + 2);
        tmp.init();
        mat ans = Pow(tmp, m);
        ans = ans * a;
        printf("%I64d\n", ans.s[n + 1][0]);
    }    
    return 0;
}
