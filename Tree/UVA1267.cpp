#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1005;
vector<int> gr[MAXN], nodes[MAXN];
int n, s, k, fa[MAXN];
bool vis[MAXN];

void dfs(int u, int f, int d) {
    fa[u] = f;
    int nc = gr[u].size();
    if (nc == 1 && d > k)
        nodes[d].push_back(u);  //利用nodes表可以省去对于叶子结点深度的搜索
    for (int i = 0; i < nc; i++)  {
        int v = gr[u][i]; 
        if (v != f) 
            dfs(v, u, d + 1);
    }
}

void dfs_cover(int u, int f, int d) {
    vis[u] = true;
    int nc = gr[u].size();
    for (int i = 0; i < nc; i++) {
        int v = gr[u][i]; 
        if (v != f && d < k)
            dfs_cover(v, u, d + 1);
    }
}

int solve() {
    int ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int d = n - 1; d > k; d--)
        for (int i = 0; i < nodes[d].size(); i++) {
            int u = nodes[d][i];
            if (vis[u])
                continue;
            int v = u;
            for (int j = 0; j < k; j++)
                v = fa[v];
            dfs_cover(v, -1, 0);
            ans++;
        }
    return ans;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &n, &s, &k); 
        for (int i = 1; i <= n; i++) {
            gr[i].clear();
            nodes[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; 
            scanf("%d%d", &a, &b);
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        dfs(s, -1, 0);
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}
