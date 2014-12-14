#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1200;

double p[15][MAXN];
double d[MAXN][MAXN];

int n, m;

void dp() {
    for (int i = 0; i <= m; i++)
        for (int j = 0; j < (1 << n); j++)
            d[i][j] = -1.0;
    d[0][0] = 0;
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < (1 << n); j++) {
            if (d[i][j] < 0) continue; 
            int st;
            for (int k = 0; k < n; k++) {
                if (!((1 << k) & j)) {
                    st = j | (1 << k);   
                    if (st == (1 << n) - 1) 
                        st = 0;
                    d[i + 1][st] = max(d[i + 1][st], d[i][j] + p[k][i]);
                } 
            } 
        }   
}

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &m);         
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                scanf("%lf", &p[i][j]);
        dp();
        double ans = 0;
        for (int i = 0; i < (1 << n); i++)
            ans = max(ans, d[m][i]);
        printf("Case #%d: %.5lf\n", t++, ans);
    }
    return 0;
}
