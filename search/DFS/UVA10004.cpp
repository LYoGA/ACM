#include <iostream>
#include <cstdio>
#include <cstring>
#define N 205

using namespace std;

int node, m;
int map[N][N], vis[N], color[N];

int dfs(int n) {
    for (int i = 0; i < node; i++) { 
        if (map[n][i]) {
            if (!vis[i]) {
                vis[i] = 1;  
                color[i] = !color[n];  
                dfs(i);
            }
            else if (color[n] == color[i]) 
                return 0;  
        }
    } 
    return 1;
}

int main() {
    while (scanf("%d", &node) && node) {
        scanf("%d", &m); 
        memset(vis, 0, sizeof(vis));
        memset(map, 0, sizeof(map));
        memset(color, 0, sizeof(color));

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            map[a][b] = 1;
            map[b][a] = 1;
        }
        vis[0] = 1;
        color[0] = 1; 
        int flag = dfs(0);
        if (flag)
            printf("BICOLORABLE.\n");
        else 
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}

