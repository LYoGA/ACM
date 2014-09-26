#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 30;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct node{
    node (int xx, int yy, int dd, int cc, int tt) {
        x = xx; 
        y = yy;
        d = dd;
        c = cc;
        t = tt;
    }
    int x, y, d, c, t;
};

char g[MAXN][MAXN];

int m, n, sx, sy, ex, ey;
int vis[MAXN][MAXN][6][6];

int bfs() {
    queue<node> q;
    while (!q.empty()) q.pop();
    node s(sx, sy, 0, 0, 0);
    q.push(s);
    memset(vis, 0, sizeof(vis));
    vis[sx][sy][0][0] = 1;
    while (!q.empty()) {
        node u = q.front(); 
        q.pop(); 

        if (u.x == ex && u.y == ey && u.c == 0)
            return u.t;

        for (int i = 0; i < 4; i++) {
            node v = u;
            if (i == u.d) {
                v.x = u.x + dx[i];
                v.y = u.y + dy[i]; 
                v.c = (u.c + 1) % 5;
                v.t = u.t + 1;
                if (v.x < 0 || v.x >= n || v.y < 0 || v.y >= m || g[v.x][v.y] == '#') continue;
                if (!vis[v.x][v.y][v.d][v.c]) {
                    vis[v.x][v.y][v.d][v.c] = 1;
                    q.push(v);
                }
            } 
            else if ((u.d + 1) % 4 == i || (u.d + 3) % 4 == i){
                if (!vis[v.x][v.y][i][v.c]) {
                    vis[v.x][v.y][i][v.c] = 1;
                    v.d = i;
                    v.t = u.t + 1;
                    q.push(v);
                }
            }
        } 
    }
    return -1; 
}

int main() {
    int t = 1, flag = 0;
    while (scanf("%d%d", &n, &m) && n && m) {
        for (int i = 0; i < n; i++)         
            scanf("%s", g[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'S') {
                    sx = i; 
                    sy = j;
                }
                if (g[i][j] == 'T') {
                    ex = i; 
                    ey = j;
                }      
            }  
        } 
        if (flag) 
            printf("\n");
        flag = 1;

        printf("Case #%d\n", t++);
        int ans = bfs();
        if (ans == -1)
            printf("destination not reachable\n");
        else 
            printf("minimum time = %d sec\n", ans);
    }    
    return 0;
}
