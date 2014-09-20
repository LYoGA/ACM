#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct mat{
    int s[4][4];
    mat() {
        memset(s, 0, sizeof(s)); 
    }
    mat operator * (const mat& c) {
        mat ans; 
        memset(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]);
        return ans;
    }
    mat operator % (int mod) {
        for (int i = 0; i < 4; i++) 
            for (int j = 0; j < 4; j++) 
                s[i][j] %= mod;
        return *this;
    }
}tmp, c;

int f[5];
int L, M;

void init() {
    memset(f, 0, sizeof(f));
    f[1] = 2;
    f[2] = 4;
    f[3] = 6;
    f[4] = 9;
    tmp.s[0][0] = f[4];
    tmp.s[1][0] = f[3];
    tmp.s[2][0] = f[2];
    tmp.s[3][0] = f[1];
    c.s[0][0] = c.s[0][2] = c.s[0][3] = c.s[1][0] = c.s[2][1] = c.s[3][2] = 1;
}

mat pow_mod(int k) {
    if (k == 1)
        return c;
    mat a = pow_mod(k / 2);
    mat ans = a * a % M;
    if (k % 2)
        ans = ans * c % M;
    return ans;
}

int main() {
    init();
    while (scanf("%d%d", &L, &M) != EOF) {
        if (L <= 4) 
            printf("%d\n", f[L] % M);   
        else {
            mat ans = pow_mod(L - 4); 
            ans = ans * tmp; 
            printf("%d\n", ans.s[0][0] % M);
        } 
    }    
    return 0;
}
