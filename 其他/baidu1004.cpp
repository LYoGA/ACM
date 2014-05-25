#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 105;

const int d[3][2] = {1, 0, -1, 0, 0, 1};
const int INF = 0x3f3f3f3f;
int map[N][N], vis[N][N][3], dp[N][N][3];
int n, m;

int dfs(int x, int y, int z) {
    int &ans = dp[x][y][z];
    if (vis[x][y][z])
        return ans;
    vis[x][y][z] = 1;
    ans = -INF;
    if (x == 0 && y == m - 1)
        return ans = map[x][y];
    for (int i = 0; i < 3; i++) {
        if ((z == 0 && i == 1) || (z == 1 && i == 0))
            continue;
        int tx = x + d[i][0]; 
        int ty = y + d[i][1]; 
        if (tx < 0 || tx >= n || ty < 0 || ty >= m)
            continue;
        ans = max(ans, dfs(tx, ty, i) + map[x][y]); 
    }
    return ans;
}

int main() {
    int cas, t = 1;    
    scanf("%d", &cas);
    while (cas--) {
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &n, &m); 
        for (int i = 0; i < n ; i++) 
            for (int j = 0; j < m; j++) 
                scanf("%d", &map[i][j]); 
        int Max = dfs(0, 0, 0);  
        printf("Case #%d:\n%d\n", t++, Max);
    }
    return 0;
}
