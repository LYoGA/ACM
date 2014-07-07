#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n, m;
int d[MAXN][MAXN], G[MAXN][MAXN];

void Input() {
    int a, b = 0;
    char s[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a); 
        gets(s); 
        for (int j = 0; j <= strlen(s); j++) {
            if (isdigit(s[j])) { 
                b = s[j] - '0' + b * 10;
            }
            else {
                G[a][b] = 1; 
                b = 0;
            }
        }
    }
}

int dp(int x, int y) {
    d[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (G[i][j]) 
                continue;
            d[i][j] = d[i][j - 1] + d[i - 1][j];
        }
    }
    return d[n][m];
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d %d", &n, &m);         
        memset(d, 0, sizeof(d));  
        memset(G, 0, sizeof(G));
        Input();
        int ans = dp(n, m);
        printf("%d\n", ans); 
        if (cas)
            printf("\n");
    }
    return 0;
}
