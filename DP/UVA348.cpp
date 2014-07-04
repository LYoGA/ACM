#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 15;
const int INF = 1 << 30;

int d[MAXN][MAXN], vis[MAXN][MAXN], x[MAXN], y[MAXN];
int n, cas;

int dp(int a, int b)  {
    if (d[a][b] != -1) 
        return d[a][b];
    vis[a][b] = a;
    if (a == b)
        return d[a][b] = 0;
    d[a][b] = INF;
    for (int i = a; i < b; i++) {
        int temp = dp(a, i) + dp(i + 1, b) + x[a] * y[i] * y[b];
        if (temp < d[a][b]) {
            d[a][b] = temp; 
            vis[a][b] = i;
        }
    }
    return d[a][b];
} 

void outPut(int a, int b) {
    if (a > b)
        return;
    if (a == b)
        printf("A%d", a + 1);
    else {
        printf("("); 
        outPut(a, vis[a][b]);
        printf(" x "); 
        outPut(vis[a][b] + 1, b);
        printf(")");
    }
}

int main() {
    cas = 1;
    while (scanf("%d", &n) && n) {
        memset(d, -1, sizeof(d));
        for (int i = 0; i < n; i++) 
            scanf("%d %d", &x[i], &y[i]);
        printf("Case %d: ", cas++);
        int ans = dp(0, n - 1);      
        outPut(0, n - 1); 
        printf("\n");
    }     
    return 0;
}
