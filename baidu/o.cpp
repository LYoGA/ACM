#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int MAXN = 100005;

int n, p[MAXN], r[MAXN][2];

int dis (int a, int b) {
    return abs(p[a] - p[b]);
}

void heat (int x, int y) {
    if (y == n + 1)
        return;
    if (r[x][0] == 0 || dis(x, y) < dis(x, r[x][0])) {
        r[x][0] = y;
    } 
    else if (dis(x, y) == dis(x, r[x][0])) {
        r[x][1] = y;
    }
}

int find (int x) {
    if (x == 0)
        return 0;
    if (r[x][0] < 0)
        return r[x][1];
    else
        return max(find(r[x][0]), find(r[x][1]));
}

int query (int x) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) <= x)
            ans++;
    }
    return ans;
}

void solve () {
    int m, a, b;
    char s[5];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        if (s[0] == 'Q') {
            scanf("%d", &a);
            printf("%d\n", query(a));
        } else {
            scanf("%d %d", &a, &b);
            r[a + 1][1] = b;
        }
    }
}

int main () {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        int mv = 0, v;
        memset(r, 0, sizeof(r));
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &p[i], &v);
            if (v) {
                mv = i;
                r[i][0] = -1;
                r[i][1] = v;
            } 
            else {
                r[i][0] = mv;
            }
        }
        mv = n + 1;
        for (int i = n; i; i--) {
            if (r[i][0] < 0) {
                mv = i;
            } 
            else {
                heat(i, mv);
            }
        }

        printf("Case #%d:\n", t++);
        solve();
    }
    return 0;
}
