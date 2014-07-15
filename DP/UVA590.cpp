#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f; 
const int MAXN = 1005;
const int N = 15;

int d[MAXN][MAXN], day[N][N], cost[N][N][MAXN];
int n, m;

void init() {
    memset(cost, 0, sizeof(cost));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            d[i][j] = INF;
    d[1][0] = 0;
}

int dp() {
    for (int k = 1; k <= m; k++) 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (i == j) 
                    continue;
                int temp = (k - 1) % day[j][i] + 1;
                if (cost[j][i][temp] && d[j][k - 1] != INF)
                    d[i][k] = min(d[i][k], d[j][k - 1] + cost[j][i][temp]); 
            }
    return d[n][m];
}

int main() {
    int t = 1;
    while (scanf("%d %d", &n, &m) && n || m) {
        init();
        for (int i = 1; i <= n; i++)   
            for (int j = 1; j <= n; j++) 
                if (i != j) {
                    scanf("%d", &day[i][j]);  
                    for (int k = 1; k <= day[i][j]; k++)
                        scanf("%d", &cost[i][j][k]);
                } 
        int ans = dp(); 

        printf("Scenario #%d\n", t++);
        if (ans != INF)  
            printf("The best flight costs %d.\n\n", ans);
        else
            printf("No flight possible.\n\n");
    } 
    return 0;
}
