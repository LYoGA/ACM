#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;
const int MOD = 6;

struct mat{
    int s[6][6];
    mat() {
        memset(s, 0, sizeof(s)); 
    }
    mat operator * (const mat& c) {
        mat ans; 
        memset(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                for (int k = 0; k < 6; k++)
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]) % MOD;
        return ans;
    }
};

int a[N][6], b[6][N], temp[N][N], sum[N][N];
int n, m;

void init() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
}

mat pow_mod(mat c, int k) {
    if (k == 1)
        return c;
    mat a = pow_mod(c, k / 2);
    mat ans = a * a;
    if (k % 2)
        ans = ans * c;
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) 
            break;
        init();
        mat c;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < n; k++)
                    c.s[i][j] = (c.s[i][j] + b[i][k] * a[k][j]) % MOD;
        int cnt = n * n - 1;
        mat ans = pow_mod(c, cnt);

        memset(temp, 0, sizeof(temp));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                for (int k = 0; k < m; k++) 
                    temp[i][j] = (temp[i][j] + a[i][k] * ans.s[k][j]) % MOD;
        cnt = 0;
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) 
                    sum[i][j] = (sum[i][j] + temp[i][k] * b[k][j]) % MOD;
                cnt += sum[i][j];
            }
        printf("%d\n", cnt); 
    }
    return 0;
}
