#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

int g[105][105], d[MAXN], arr[MAXN], v[MAXN], path[MAXN];
int n, m, cnt;

void init () {
    memset(g, 0, sizeof(g));
    int a, b;  
    cnt = 0;
    while (scanf("%d %d", &a, &b) && a && b) {
        g[a][b] = 1;  
        //arr[cnt++] = (a - 1) * m + b - 1;  
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j])
                arr[cnt++] = (i - 1) * m + j - 1;
    if (!g[n][m])
        arr[cnt++] = n * m - 1;
}

void LIS() {
    memset(path, -1, sizeof(path));
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    for (int i = 0; i < cnt; i++) {
        d[i] = 1, v[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] % m >= arr[j] % m) {
                if (d[i] < d[j] + 1) {
                    d[i] = d[j] + 1; 
                    path[i] = j;
                    v[i] = v[j];
                }
                else if (d[i] == d[j] + 1) 
                    v[i] += v[j];
            }
    }
    if (!g[n][m])
        d[cnt - 1]--;
}

void outPut(int u) {
    if (path[u] != -1)
        outPut(path[u]);
    if (u != cnt - 1 || g[n][m])
        printf(" %d", arr[u] + 1); 
}

int main() {
    int t = 1;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == -1 && m == -1) 
            break;
        init();
        LIS();  
        printf("CASE#%d: %d %d", t++, d[cnt - 1], v[cnt - 1]);
        outPut(cnt - 1);
        printf("\n");
    }
    return 0;
}
