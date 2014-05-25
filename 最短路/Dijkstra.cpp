#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 20005;
const int M = 50005;
const int INF = 1 << 20;
int n, m, s, t;
int d[N], vis[N], w[N][N];

void init() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < n; i++)
        d[i] = (i == s ? 0 : INF);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c); 
        w[a][b] = w[b][a] = c; 
    }
}

void dijkstra() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        int x, k = INF;
        for (int y = 0; y < n; y++)
            if (!vis[y] && d[y] <= k)
                k = d[x = y];
        vis[x] = 1;
        for (int y = 0; y < n; y++) 
            if (d[y] > d[x] + w[x][y]) { 
                d[y] = d[x] + w[x][y];
            }
    }
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init();         
        dijkstra();    
        printf("%d\n", d[t]);
    }
    return 0;
}
