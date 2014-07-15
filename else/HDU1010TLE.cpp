#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 100;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int n, m, t, flag, wall;
int a, b, c, d; 
int arr[N][N], vis[N][N];
char map[N][N];

void init() { 
    flag = wall = 0;
    for (int i = 0; i < n; i++)  
        gets(map[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'S') {
                arr[i][j] = 0;
                a = i; 
                b = j;
            } 
            else if (map[i][j] == 'D') {
                arr[i][j] = 0; 
                c = i; 
                d = j;
            }
            else if (map[i][j] == 'X') {
                arr[i][j] = 1; 
                wall++; 
            }
            else 
                arr[i][j] = 0; 
        } 
    }
}

void dfs(int x, int y, int z) {
    if (flag) return;
    int temp = (abs(x - c) + abs(y - d)) - abs(z - t);
    if (z > t && temp < 0 || temp % 2 != 0) return;
    if (x == c && y == d && z == t) {
        flag = 1;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i]; 
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && !arr[tx][ty] && !vis[tx][ty]) {
            vis[tx][ty] = 1;
            dfs(tx, ty, z + 1); 
            vis[tx][ty] = 0;
        }
    }
    z--;
    return;
}

int main() {
    while (scanf("%d %d %d", &n, &m, &t) && n && m && t) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = 0;
                vis[i][j] = 0;
            } 
        }
        getchar();
        init(); 
        vis[a][b] = 1;
        if (n * m - wall < t) {
            printf("NO\n");
            continue; 
        }
        int v = t - (abs(a - c) + abs(b - d));
        if (v % 2 == 0)
            dfs(a, b, 0);  
        if (flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
