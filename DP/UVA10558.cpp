#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 110;

int N, S, A;
int street[MAXN], g[MAXN][MAXN], e[MAXN][MAXN], f[MAXN][MAXN], sum[MAXN][MAXN];
int vis[MAXN][MAXN], d[MAXN][MAXN], path[MAXN][MAXN];

void init() {
    memset(e, 0, sizeof(e));
    memset(f, 0, sizeof(f));
    memset(sum, 0, sizeof(sum));
    for (int k = 1; k < S; k++)
        for (int i = 1; i < 100; i++) {
            for (int j = street[k]; j < street[k + 1]; j++)
                if (g[i][j] == 1) { 
                    e[i][k]=1; 
                    break; 
                }
            f[i][k] = e[i][k];
            f[i][k] += f[i-1][k];
        }

    for (int i = 1; i < 100; i++)
        for (int j = i + 1; j <= 100; j++) 
            for (int k = 1; k < S; k++)
                if (f[j - 1][k] - f[i][k] + e[i][k])
                    sum[i][j]++;
}

int dp(int i, int j) {
    if (vis[i][j]) 
        return d[i][j];
    vis[i][j] = 1;
    if (j == 0)
        return d[i][j] = sum[i][100];
    for (int k = i + 1; k < 100; k++) {
        if (100 - k - 1 < j - 1) 
            break;
        if (d[i][j] < dp(k, j - 1) + sum[i][k]) {
            d[i][j] = dp(k, j - 1) + sum[i][k];
            path[i][j] = k; 
        } 
    } 
    return d[i][j];
}

void outPut(int i, int j) {
    if (j <= 0)
        return;
    printf(" %d", path[i][j]);
    outPut(path[i][j], j - 1);
}

int main() {
    while (scanf("%d", &N) && N != -1) {
        int x, y;
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= N; i++) {
            scanf("%d %d", &x, &y); 
            g[y][x] = 1;
        }
        scanf("%d", &S);
        for (int i = 1; i <= S; i++)
            scanf("%d", &street[i]);
        scanf("%d", &A);
        init(); 

        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        dp(1, A - 2);

        printf("%d", A);
        printf(" 1");
        outPut(1, A - 2);
        printf(" 100\n"); 
    } 
    return 0;
}
