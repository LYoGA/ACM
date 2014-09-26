#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

struct node{
    node (int xx, int yy, int dd) {
        x = xx; 
        y = yy;
        d = dd;
    }
    int x, y, d;
};

char g[MAXN][MAXN];
int vf[MAXN][MAXN], vm[MAXN][MAXN], T[MAXN][MAXN];
int r, c, sx, sy;

queue<node> qf;

void bfs_fire() {
    while (!qf.empty()) {
        node u = qf.front(); 
        qf.pop(); 
        node v = u;
        for (int i = 0; i < 4; i++) {
            int tx = u.x + dx[i]; 
            int ty = u.y + dy[i];      
            if (tx < 0 || tx >= r || ty < 0 || ty >= c || g[tx][ty] == '#') continue;
            if (!vf[tx][ty]) {
                vf[tx][ty] = 1; 
                v.x = tx; 
                v.y = ty;
                v.d = u.d + 1;
                T[tx][ty] = v.d;
                qf.push(v);
            }  
        }
    }
}

int bfs_man() {
    queue<node> qm;
    while (!qm.empty()) qm.pop(); 
    node s(sx, sy, 0);
    qm.push(s);
    memset(vm, 0, sizeof(vm));
    vm[sx][sy] = 1;
    while (!qm.empty()) {
        node u = qm.front(); 
        qm.pop(); 
        if (u.x == 0 || u.x == r - 1 || u.y == 0 || u.y == c - 1)
            return u.d + 1;
        node v = u;
        for (int i = 0; i < 4; i++) {
            int tx = u.x + dx[i]; 
            int ty = u.y + dy[i]; 
            if (tx < 0 || tx >= r || ty < 0 || ty >= c || g[tx][ty] == '#') continue;
            if (u.d + 1 >= T[tx][ty]) continue;
            if (!vm[tx][ty]) {
                vm[tx][ty] = 1; 
                v.x = tx; 
                v.y = ty;
                v.d = u.d + 1;
                qm.push(v);
            }
        }
    }
    return -1;
}

int main() {
    int cas; 
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; i++)
            scanf("%s", g[i]);

        while(!qf.empty())  qf.pop();
        memset(vf, 0, sizeof(vf));
        memset(T, INF, sizeof(T));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 'J') {
                    sx = i; 
                    sy = j; 
                }
                if (g[i][j] == 'F') {
                    node tmp(i, j, 0);       
                    vf[i][j] = 1;
                    T[i][j] = 0;
                    qf.push(tmp);
                } 
            } 
        }

        bfs_fire();
        int ans = bfs_man();    
        if (ans == -1) 
            printf("IMPOSSIBLE\n");
        else 
            printf("%d\n", ans);
    }
    return 0;
}
