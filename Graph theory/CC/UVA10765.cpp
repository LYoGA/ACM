#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct node{
    int id, val;
}b[MAXN];

int n, m;
int pre[MAXN], low[MAXN], dfs_clock;
vector<int> g[MAXN];

void init() {
    for (int i = 0; i < n; i++) 
        g[i].clear();
    for (int i = 0; i < n; i++) {
        b[i].id = i; 
        b[i].val = 1;
    }     
}

bool cmp(node a, node b) {
    if (a.val == b.val)
        return a.id < b.id;
    return a.val > b.val;
}

int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (!pre[v]) {
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u]) {
                b[u].val++;
            }
        } 
        else if (pre[v] < pre[u] && v != fa) {
            lowu = min(lowu, pre[v]);
        }
    }
    if (fa < 0 && child == 1) b[u].val = 1;
    low[u] = lowu;
    return lowu;
}

void find_bcc(int n) {
    memset(pre, 0, sizeof(pre));
    memset(low, 0, sizeof(low));
    dfs_clock = 0;
    for (int i = 0; i < n; i++)
        if (!pre[i])
            dfs(i, -1);
}

int main() {
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        init();
        int u, v;
        while (scanf("%d%d", &u, &v)) {
            if (u == -1 && v == -1)
                break;
            g[u].push_back(v);
            g[v].push_back(u); 
        }

        find_bcc(n);
        sort(b, b + n, cmp);
        for (int i = 0; i < m; i++)
            printf("%d %d\n", b[i].id, b[i].val);
        puts("");
    }     
    return 0;
}

