#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 505;
const int dx[] = {-1, 0, 1, 0, 0};
const int dy[] = {0, -1, 0, 1, 0};

int vis[N][N][5], b[N][N][5];
char g[N][N];

int n, sx, sy, ex, ey;

struct node{
    node(int xx, int yy, int dd) {
        x = xx; 
        y = yy;
        d = dd;
    }
    int x, y, d;
    friend bool operator < (node a, node b) {
        return a.d > b.d; 
    }
};

int bfs(int x,int y) {
    priority_queue <node> q ;
    node s(x, y, 0);
    q.push(s) ;
    memset(vis,0,sizeof(vis)) ;
    vis[x][y][0] = 1 ;
    while(!q.empty()) {
        node u = q.top() ;
        q.pop();

        if(u.x == ex && u.y == ey) 
            return u.d ; 

        for(int i = 0 ;i < 5 ;i++) {
            int tx = u.x + dx[i] ;
            int ty = u.y + dy[i] ;

            if(tx < 0 || tx >= n || ty < 0 || ty >= n || g[tx][ty] == '#')continue ;

            node p = u;
            if(b[tx][ty][u.d%4] || b[u.x][u.y][u.d%4]) {
                if(tx == u.x && ty == u.y && !vis[tx][ty][(u.d+1)%4]) {
                    p.d++ ;
                    vis[tx][ty][p.d%4]=1 ;
                    q.push(p) ;
                }
                else if(!vis[tx][ty][(u.d+3)%4]) {
                    p.x=tx;
                    p.y=ty ;
                    p.d += 3 ;
                    vis[tx][ty][p.d%4]=1 ;
                    q.push(p) ;
                }
            }
            else if(!vis[tx][ty][(u.d+1)%4]) {
                p.x=tx;
                p.y=ty;
                p.d++ ;
                vis[tx][ty][p.d%4]=1 ;
                q.push(p) ;
            }
        }
    }
    return -1 ;
}

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)   
            scanf("%s", g[i]);

        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 'M') {
                    sx = i; 
                    sy = j; 
                } 
                else if (g[i][j] == 'T') {
                    ex = i; 
                    ey = j; 
                }
                else if (g[i][j] == 'N') {
                    b[i][j][0] = b[i][j][1] = b[i][j][2] = b[i][j][3] = 1;
                    if (i - 1 >= 0) b[i - 1][j][0] = 1;
                    if (j + 1 < n) b[i][j + 1][1] = 1;
                    if (i + 1 < n) b[i + 1][j][2] = 1;
                    if (j - 1 >= 0) b[i][j - 1][3] = 1;
                }
                else if (g[i][j] == 'W') {
                    b[i][j][0] = b[i][j][1] = b[i][j][2] = b[i][j][3] = 1;
                    if (j - 1 >= 0) b[i][j - 1][0] = 1;
                    if (i - 1 >= 0) b[i - 1][j][1] = 1;
                    if (j + 1 < n) b[i][j + 1][2] = 1; 
                    if (i + 1 < n) b[i + 1][j][3] = 1;
                }
                else if (g[i][j] == 'S') {
                    b[i][j][0] = b[i][j][1] = b[i][j][2] = b[i][j][3] = 1;
                    if (i + 1 < n) b[i + 1][j][0] = 1;
                    if (j - 1 >= 0) b[i][j - 1][1] = 1;
                    if (i - 1 >= 0) b[i - 1][j][2] = 1;
                    if (j + 1 < n) b[i][j + 1][3] = 1; 
                }
                else if (g[i][j] == 'E') {
                    b[i][j][0] = b[i][j][1] = b[i][j][2] = b[i][j][3] = 1;
                    if (j + 1 < n) b[i][j + 1][0] = 1; 
                    if (i + 1 < n) b[i + 1][j][1] = 1;
                    if (j - 1 >= 0) b[i][j - 1][2] = 1;
                    if (i - 1 >= 0) b[i - 1][j][3] = 1;
                }
            }
        printf("Case #%d: %d\n", t++, bfs(sx, sy));
    }
    return 0;
}
