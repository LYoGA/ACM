#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n, num, cnt, color[MAXN];
int g[MAXN][MAXN];

bool bipartite(int u, int col) {
    color[u] = col;
    if (color[u] == 0) cnt++;
    if (color[u] == 1) num++;
    for (int i = 1; i <= n; i++) {
        if (g[u][i]) {
            if (color[i] != -1) {
                if (color[i] == col) return false; 
                continue;
            }
            if (!bipartite(i, !col)) return false;
        }
    }
    return true;
}

int main() {
    int cas; 
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        memset(g, 0, sizeof(g));
        int m; 
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m);
            while (m--) {
                int j;
                scanf("%d", &j); 
                g[i][j] = g[j][i] = 1;
            }
        }

        int ans = 0;
        memset(color, -1, sizeof(color));
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) { 
                num = cnt = 0;
                if(bipartite(i, 0)) {
                    ans += max(num, cnt); 
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

