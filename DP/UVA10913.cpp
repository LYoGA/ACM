#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 85;
const int dx[] = {0, 0, 1};
const int dy[] = {-1, 1, 0};

int n, k;
int g[MAXN][MAXN], vis[MAXN][MAXN]; 
ll d[MAXN][MAXN][10][10], ans;

void init() {
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int kk = 0; kk < 6; kk++)
                for (int l = 0; l < 3; l++)
                    d[i][j][kk][l] = -INF; 
    memset(vis, 0, sizeof(vis));
    vis[1][1] = 1;
    ans = -INF;
}

void dfs(int x, int y, int cnt, ll sum) {
    if (cnt > k) 
        return;  
    if (x == n && y == n) { 
        ans = max(ans, sum); 
        return; 
    } 
    for (int i = 0; i < 3; i++) {
        int tx = x + dx[i]; 
        int ty = y + dy[i]; 
        if (tx > 0 && tx <= n && ty > 0 && ty <= n && !vis[tx][ty]) {
            vis[tx][ty] = 1; 
            if (g[tx][ty] >= 0 && d[tx][ty][cnt][i] < sum + g[tx][ty]) {
                d[tx][ty][cnt][i] = sum + g[tx][ty];
                dfs(tx, ty, cnt, d[tx][ty][cnt][i]);
            } 
            else if (g[tx][ty] < 0 && d[tx][ty][cnt + 1][i] < sum + g[tx][ty]){
                d[tx][ty][cnt + 1][i] = sum + g[tx][ty];
                dfs(tx, ty, cnt + 1, d[tx][ty][cnt + 1][i]); 
            }
            vis[tx][ty] = 0;
        }  
    }    
}

int main() {
    int t = 1; 
    while (scanf("%d %d", &n, &k) && n || k) {
        init();

        if (g[1][1] >= 0) {
            dfs(1, 1, 0, g[1][1]); 
        }
        else
            dfs(1, 1, 1, g[1][1]);

        printf("Case %d: ", t++);  
        if(ans == -INF)
            printf("impossible\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}
