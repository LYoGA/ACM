#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 55;
const int MAXM = 10005;

vector<int> p[MAXN];
double dp[MAXM][MAXN];

int n, m, d;

void init() {
    for (int i = 0; i <= n; i++)
        p[i].clear();
}

double solve(int a) {

    memset(dp, 0, sizeof(dp));
    double ans = 0;
    dp[0][0] = 1;

    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == a) 
                continue;
            double b = 1.0 / p[j].size();
            for (int k = 0; k < p[j].size(); k++) 
                dp[i + 1][p[j][k]] += dp[i][j] * b;
        }  
        ans += dp[i + 1][a];
    }
    return 1.0 - ans;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &n, &m, &d);
        init();
        int x, y;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y); 
            p[x].push_back(y);
            p[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            p[0].push_back(i);

        for (int i = 1; i <= n; i++) {
            double ans = solve(i);  
            printf("%.10lf\n", ans);
        } 
    }
    return 0;
}
