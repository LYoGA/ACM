#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct queue{
    int x, y, d;
};

const int N = 205;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, ans, sx, sy, ex, ey, flag, vis[N][N], arr[N][N];
char map[N][N];

void init() {
    memset(vis, 0, sizeof(vis));
    memset(vis, 0, sizeof(arr));
    ans = N * 100;
    flag = 0;
    for (int i = 0; i < n; i++)
        scanf("%s", &map[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'r') {
                sx = i;  
                sy = j; 
                arr[i][j] = 0;
            } 
            else if (map[i][j] == 'a') {
                ex = i; 
                ey = j; 
                arr[i][j] = 0;
            }
            else if (map[i][j] == '.') 
                arr[i][j] = 0;
            else if (map[i][j] == '#') 
                arr[i][j] = 1;
            else if (map[i][j] == 'x')
                arr[i][j] = 2;
        }      
    }
}

void dfs(int x, int y, int z) {
    if (z > ans) return;
    if (x == ex && y == ey) {
        if (ans > z)
            ans = z; 
        flag = 1;
        return; 
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i]; 
        int ty = y + dy[i]; 
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty] && (arr[tx][ty] == 0 || arr[tx][ty] == 2)) {
            vis[tx][ty] = 1;
            if (arr[tx][ty] == 0)
                dfs(tx, ty, z + 1);
            else
                dfs(tx, ty, z + 2);
            vis[tx][ty] = 0; 
        } 
    }
}

int main() {
    while (scanf("%d %d", &n, &m)) {
        init(); 
        vis[sx][sy] = 1;
        dfs(sx, sy, 0); 
        if (flag)
            printf("%d\n", ans);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}
