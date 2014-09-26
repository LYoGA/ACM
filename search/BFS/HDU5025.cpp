#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 105;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

char g[MAXN][MAXN];
int d[MAXN][MAXN][10][33];
int n, m, sn;
int sx, sy;

struct node{
    int x, y, k, s, d;
    node(int xx, int yy, int kk, int ss, int dd) {
        x = xx; 
        y = yy;
        k = kk; 
        s = ss;
        d = dd;
    }
};

void init() {
    sn = 0;
    memset(g, 0, sizeof(g));
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%c", &g[i][j]);
            if (g[i][j] == 'S') {
                g[i][j] = 'A' + sn;
                sn++;
            }
            if (g[i][j] == 'K') {
                sx = i; 
                sy = j;
            }
        }
        getchar();
    }
}

int bfs(int x, int y, int key, int snum) {
    queue<node> q;
    while (!q.empty()) 
        q.pop();
    int ans = INF;
    node start(x, y, key, snum, 0);
    q.push(start);

    while (!q.empty()) {
        node tmp = q.front(); 
        q.pop();
        x = tmp.x; 
        y = tmp.y;
        key = tmp.k;
        snum = tmp.s;

        if (key == m && g[x][y] == 'T') 
            ans = min(ans, tmp.d); 

        if (d[x][y][key][snum] != -1)
            continue;
        d[x][y][key][snum] = tmp.d;

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            int st = g[tx][ty] - 'A';

            if (st >= 0 && st < sn) {
                if (snum & (1 << st))         
                    q.push(node(tx, ty, key, snum, tmp.d + 1));
                else
                    q.push(node(tx, ty, key, (snum | (1 << st)), tmp.d + 2)); 
            } 
            else if (g[tx][ty] == '1' + key) 
                q.push(node(tx, ty, key + 1, snum, tmp.d + 1)); 
            else if (g[tx][ty] >= '1' && g[tx][ty] < '1' + m) 
                q.push(node(tx, ty, key, snum, tmp.d + 1)); 
            else if (g[tx][ty] == '.' || g[tx][ty] == 'K' || g[tx][ty] == 'T') 
                q.push(node(tx, ty, key, snum, tmp.d + 1));  
        } 
    }
    return ans;
}

int main() {
    while (scanf("%d %d", &n, &m) && (n || m)) {
        getchar();
        init();

        int ans = bfs(sx, sy, 0, 0);
        if (ans >= INF)
            printf("impossible\n");
        else
            printf("%d\n", ans); 
    }
    return 0;
}
