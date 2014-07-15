#include <stdio.h>
#include <string.h>
#define N 10000

int map[N][N], vis[N];
int n, m;

void dfs(int u) {
    vis[u] = 1;
    for (int i = 1; i <= n; i++) 
        if (!vis[i] && map[u][i]) 
            dfs(i); 
}

int connect() {
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            return 0;
    return 1;
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF){
        int a, b, t, max = 0;
        memset(map, 0, sizeof(map));
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &t); 
            map[a][b] = t;
            map[b][a] = t;
            if (max < t)
                max = t;
        }
        int cnt = 0; 
        for (int i = 0; i < t; i++) {
            for (int i = 1; i <= n; i++)   
                for (int j = 1; j <=n; j++) {
                    if (map[i][j] > 0) 
                        map[i][j]--; 
                }
            memset(vis, 0, sizeof(vis));
            dfs(1); 
            if (!connect()) 
                cnt++;
        }
        printf("%d\n", cnt); 
    } 
     return 0;
}
