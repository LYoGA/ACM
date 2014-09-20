#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 205;
const int N = 10;

ll n, m;
int r;

struct mat {
    ll s[N][N];
    mat () { 
        memset(s, 0, sizeof(s));
    }
    mat operator * (const mat& c) {
        mat ans; 
        memset(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) 
                for (int k = 0; k < 3; k++)
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]) % m;
        return ans;  
    }
};

mat pow_mod(mat a, int k) {
    if (k == 1)
        return a;
    mat x = pow_mod(a, k / 2);
    x = x * x;
    if (k % 2) 
        x = x * a;
    return x;
}

void init() {
    if (n == 1)
        r = 1;
    else if (n == 2)
        r = 2;
    else {
        mat state; 
        state.s[0][0] = state.s[0][1] = state.s[1][0] = state.s[2][0] = state.s[2][1] = state.s[2][2] = 1;
        mat ans = pow_mod(state, n - 2);
        r = (ans.s[0][0] + ans.s[1][0] + ans.s[2][0] + 1) % m;
    }
}

void solve() {
    if (r == 0 || r % 2)
        printf("No\n");
    else {
        int v[MAXN][MAXN]; 
        memset(v, -1, sizeof(v));
        printf("Yes\n");
        for (int i = 1; i <= r; i++) {
            int tmp; 
            if (i % 2) {
                tmp = (r + i + 1) / 2; 
                v[tmp][i] = 0;
            }
            else 
                tmp = (r - i) / 2; 
            for (int j = tmp + 1; j <= r; j++) 
                v[j][i] = 1;
        } 
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= r; j++)
                printf("%d ", v[i][j]);
            printf("\n");
        }
    } 
}

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%lld%lld", &n, &m);   
        printf("Case %d: ", t++);
        init();  
        solve();
    }
    return 0;
}
