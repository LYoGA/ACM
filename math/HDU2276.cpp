#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 105;

struct mat{
    int s[MAXN][MAXN];
    int l;
    mat(int len) {
        memset(s, 0, sizeof(s)); 
        l = len;
    }
    mat operator * (const mat& c) {
        mat ans(l); 
        memset(ans.s, 0, sizeof(ans.s)); 
        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++) {
                for (int k = 0; k < l; k++)
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]);
                ans.s[i][j] = ans.s[i][j] % 2;
            }
        return ans;
    }
};

char str[MAXN];
int t;

mat pow_mod(mat c, int k) {
    /*if (k == 1)
        return c; 
    mat a = pow_mod(c, k / 2); 
    mat ans = a * a;
    if (k % 2)
        ans = ans * c;
    return ans;*/
    mat ans = c;
    k--;
    while (k) {
        if (k & 1) 
            ans = ans * c;
        k >>= 1;
        c = c * c;
    }
    return ans;
}

int main() {
    while (scanf("%d", &t) != EOF) {
        scanf("%s", str); 
        int l = strlen(str);
        mat c(l);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++) {
                if (i == 0) 
                    c.s[i][0] = c.s[i][l - 1] = 1;
                else
                    c.s[i][i - 1] = c.s[i][i] = 1;
            }
        mat tmp(l);
        for (int i = 0; i < l; i++)
            tmp.s[i][0] = str[i] - '0';
        mat ans = pow_mod(c, t);
        ans = ans * tmp;
        for (int i = 0; i < l; i++)
            printf("%d", ans.s[i][0]);
        printf("\n");
    }
    return 0;
}
