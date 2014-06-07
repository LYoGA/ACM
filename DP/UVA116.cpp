#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int d[MAXN][MAXN], arr[MAXN][MAXN];
int n, m;

int change(int x) {
    if (x == 0)
        x = n;
    else if (x == n + 1)
        x = 1;
    return x;
}

int dp(int x, int y) {
    x = change(x);
    if (d[x][y] != -INF)
        return d[x][y];
    return d[x][y] = arr[x][y] + min(min(dp(x - 1, y + 1), dp(x, y + 1)), dp(x + 1, y + 1));
}

void output(int c, int r) {
    if (r < m)
        printf("%d ", c);
    else {
        printf("%d\n", c); 
        return;
    }
    int dis[3] = {change(c - 1), change(c), change(c + 1)};
    sort(dis, dis + 3);
    int k = d[c][r] - arr[c][r];
    if (k == d[dis[0]][r + 1])
        output(dis[0], r + 1);
    else if (k == d[dis[1]][r + 1])
        output(dis[1], r + 1);
    else
        output(dis[2], r + 1);
}

int main() {
    while (scanf("%d %d", &n, &m)) {
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) {
                scanf("%d", &arr[i][j]);
                if (j == m) 
                    d[i][j] = arr[i][j];
                else 
                    d[i][j] = -INF;
            }
        int Min = INF, num, c;
        for (int i = 1; i <= n; i++) {
            num = dp(i, 1); 
            if (Min > num) {
                Min = num; 
                c = i; 
            } 
        } 
        output(c, 1);
        printf("%d\n", Min);
    }
    return 0;
}
