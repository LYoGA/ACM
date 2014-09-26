#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 505;
const int INF = 0x3f3f3f3f;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1}; 

struct node{
    node(int xx, int yy, int tt) {
        x = xx; 
        y = yy;
        t = tt;
    }
    int x, y, t;
};

char map[MAXN][MAXN];
int g[MAXN][MAXN], d[MAXN][MAXN][5];
int n, sx, sy, ex, ey;

int change(char c) {
    if (c == 'N') return 0;
    if (c == 'E') return 3;
    if (c == 'S') return 2;
    if (c == 'W') return 1;
    return -1;
}

int bfs(int x, int y, int t) {
    queue<node> q;
    node s(x, y, 0);
    q.push(s); 
    memset(d, INF, sizeof(d));
    d[s.x][s.y][s.t] = 0;
    int ans = INF; 
    while (!q.empty()) {
        node u = q.front(); 
        q.pop();
        node v = u;               
        
        if (v.x == ex && v.y == ey)
            ans = min(ans, d[v.x][v.y][v.t]);

        v.t = (v.t + 1) % 4;
        if (d[v.x][v.y][v.t] > d[u.x][u.y][u.t] + 1) {
            d[v.x][v.y][v.t] = d[u.x][u.y][u.t] + 1;
            q.push(v);
        }
        for (int i = 0; i < 4; i++) {
            node v = u; 
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];
            int step = 0;
            if (v.x < 0 || v.x >= n || v.y < 0 || v.y >= n || g[v.x][v.y] == -1) continue;
            if ((g[u.x][u.y] & (1<<u.t)) || (g[v.x][v.y] & (1<<u.t))) {
                v.t = (v.t + 3) % 4; 
                step = 3;
            }
            else {
                v.t = (v.t + 1) % 4; 
                step = 1;
            }
            if (d[v.x][v.y][v.t] > d[u.x][u.y][u.t] + step) {
                d[v.x][v.y][v.t] = d[u.x][u.y][u.t] + step;
                q.push(v);
            }
        }
    }
    return ans;
}

int main() {
    int cas, t = 1;    
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);  
        memset(g, 0, sizeof(g));
        memset(map, 0, sizeof(map));
        for (int i = 0; i < n; i++) {
            scanf("%s", map[i]);
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 'M') {
                    sx = i; 
                    sy = j;
                }
                else if (map[i][j] == 'T') {
                    ex = i;
                    ey = j;
                }
                else if (map[i][j] == '#')
                    g[i][j] = -1;
                else if (change(map[i][j]) != -1) {
                    g[i][j] = 15; 
                    for (int k = 0; k < 4; k++) {
                        int tx = i + dx[k]; 
                        int ty = j + dy[k];
                        if (tx < 0 || tx >= n || ty < 0 || ty >= n || map[tx][ty] == '#') continue;
                        g[tx][ty] |= (1<<((change(map[i][j]) + k) % 4));
                    } 
                }
            }
        }

        printf("Case #%d: ", t++);
        int ans = bfs(sx, sy, 0);
        if (ans >= INF)
            printf("-1\n");
        else 
            printf("%d\n", ans);
    }
    return 0;
}
