#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
using namespace std;

const int MAXN = 205;
const int INF = 0x3f3f3f3f;

int p[MAXN], vis[MAXN][MAXN]; 
ll dis[MAXN][MAXN], d[MAXN][MAXN];
int n, m;

void init() {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = i; k <= j; k++)
                dis[i][j] += abs(p[(i + j) / 2] - p[k]);

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            d[i][j] = INF;

    for (int i = 1; i <= n; i++)
        d[1][i] = dis[1][i];
}

void outPut(int cnt, int x, int y) {
    printf("Depot %d at restaurant %d serves ", cnt, (x + y) / 2);
    if (x == y)
        printf("restaurant %d\n", x);
    else 
        printf("restaurants %d to %d\n", x, y);
}

void print(int x, int y) {
    if (x > 1)
        print(x - 1, vis[x][y]);
    outPut(x, vis[x][y] + 1, y); 
}

int main() {
    int t = 1;
    while (scanf("%d %d", &n, &m) && n || m) {
        for (int i = 1; i <= n; i++) 
            scanf("%d", &p[i]);
        init();

        for (int i = 2; i <= m; i++)
            for (int j = i; j <= n; j++) 
                for (int k = i - 1; k < j; k++) 
                    if (d[i][j] > d[i - 1][k] + dis[k + 1][j]) {
                        d[i][j] = d[i - 1][k] + dis[k + 1][j]; 
                        vis[i][j] = k;
                    }

        printf("Chain %d\n", t++); 
        print(m, n);
        printf("Total distance sum = %lld\n\n", d[m][n]);

    }    
}
