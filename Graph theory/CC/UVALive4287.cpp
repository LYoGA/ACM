#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 20005;

vector<int> g[MAXN];
stack<int> s;
int pre[MAXN], lowlink[MAXN], sccno[MAXN], dfs_clock, scc_cnt;
int in[MAXN], out[MAXN];
int n, m;

int Tarjan(int u) {
    pre[u] = lowlink[u] = ++dfs_clock;
    s.push(u); 
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (!pre[v]) {
            Tarjan(v); 
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } 
        else if (!sccno[v]) {
            lowlink[u] = min(lowlink[u], pre[v]); 
        }
    }
    if (lowlink[u] == pre[u]) {
        scc_cnt++; 
        for (;;) {
            int x = s.top(); 
            s.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}

void find_scc() {
    memset(pre, 0, sizeof(pre));
    memset(sccno, 0, sizeof(sccno));
    memset(lowlink, 0, sizeof(lowlink));
    dfs_clock = scc_cnt = 0;
    for (int i = 0; i < n; i++)
        if (!pre[i])
            Tarjan(i);
}

int main() {
    int cas; 
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &m);         
        for (int i = 0; i < n; i++)
            g[i].clear();
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v); 
            u--;
            v--;
            g[u].push_back(v);
        }

        find_scc();
    
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        for (int i = 1; i <= scc_cnt; i++)
            in[i] = out[i] = 1;
        for (int u = 0; u < n; u++)
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i]; 
                if (sccno[u] != sccno[v]) 
                    in[sccno[v]] = out[sccno[u]] = 0;
            }
        int a = 0, b = 0;
        for (int i = 1; i <= scc_cnt; i++) {
            if (in[i]) a++; 
            if (out[i]) b++; 
        }
        int ans = max(a, b);
        if (scc_cnt == 1) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
