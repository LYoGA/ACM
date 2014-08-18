#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

char g[MAXN][MAXN];
int n, m, vis[30];

int judge(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (isupper(g[i][j])) {
                if (g[i][j] != g[x1][y1]) 
                    return 0;
            }
        }  
    } 
    return 1;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isupper(g[i][j])) {
                int a = j, b = i; 
                while (g[i][a + 1] == g[i][j]) {
                    a++; 
                } 
                while (g[b + 1][j] == g[i][j]) {
                    b++; 
                } 
                if (b - i < 2 || a - j < 2)
                    continue;
                if (g[b][a] == g[i][j] && judge(i, j, b, a))
                    vis[g[i][j] - 'A'] = 1;
            } 
        }  
    }
}

int main() {
    while (scanf("%d%d", &n, &m) && n && m) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) 
            scanf("%s", g[i]);;
        solve();
        for (int i = 0; i < 30; i++) 
            if (vis[i])
                printf("%c", i + 'A');
        printf("\n");
    } 
    return 0;
}
