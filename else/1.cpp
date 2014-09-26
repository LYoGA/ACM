#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 105;

const int dx[] = {0, 1, 0};
const int dy[] = {-1, 0, 1};
int map[N][N], vis[N][N];
int n, m, max;

void dfs(int x, int y, int num) {
    if (num > max && x == n - 1 && y == m - 1) {
        max = num; 
        return;
    }
    for (int i = 0; i < 3; i++) {
        int tx = x + dx[i]; 
        int ty = y + dy[i]; 
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty]) {
            vis[tx][ty] = 1;
            dfs(tx, ty, num + map[tx][ty]); 
            vis[tx][ty] = 0;
        }
    }
}

int main() {
    int cas, t = 1;    
    scanf("%d", &cas);
    while (cas--) {
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &m, &n); 
        for (int i = 0; i < m ; i++) 
            for (int j = 0; j < n; j++) 
                scanf("%d", &map[i][j]); 
        max = -1;
        vis[0][0] = 1;
        dfs(0, 0, map[0][0]);  
        printf("Case #%d:\n%d\n", t++, max);
    }
    return 0;
}
