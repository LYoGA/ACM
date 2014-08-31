#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

char str[MAXN][MAXN];
int g[MAXN][MAXN];
int n, ans, dir;

void init() {
    ans = 0;
    getchar();
    memset(g, -1, sizeof(g));
    for (int i = 0; i < n; i++) {
        gets(str[i]);
        for (int j = 0; j < strlen(str[i]); j++)
            if (str[i][j] == '-')
                g[i][j] = 0;
    }
}

void dfs(int x, int y, int cnt) {
    if (x < 0 || x > n) {
        ans = max(ans, cnt); 
        return;
    } 
    for (int i = y - cnt; i <= y + cnt; i++) {
        if (g[x][i] == -1) {
            ans = max(ans, cnt); 
            return;
        }       
    }
    dfs(x + dir, y, cnt + 1);    
}

int main() {
    int t = 0;
    while (scanf("%d", &n) == 1 && n) {
        init();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < 2 * (n - i) + i - 1; j++) {
                if (!g[i][j]) {
                    if ((i + j) % 2) {
                        dir = 1;
                        dfs(i, j, 0);
                    }
                    else {
                        dir = -1;
                        dfs(i, j, 0);  
                    }
                } 
            }
        }
        printf("Triangle #%d\n", ++t);
        printf("The largest triangle area is %d.\n\n", ans * ans);
    }
    return 0;
}

