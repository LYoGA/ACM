#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 1050;

struct edge{
    edge() {}
    edge(int uu, int vv) {
        u = uu; 
        v = vv;
    }
    int u, v;
};

vector<int> g[MAXN], bcc[MAXN];
stack<edge> S;
int pre[MAXN], bccno[MAXN], iscut[MAXN], odd[MAXN], color[MAXN], map[MAXN][MAXN];
int n, m, dfs_clock, bcc_cnt;

int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        edge e(u, v);
        if (!pre[v]) {
            S.push(e); 
            child++;  
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u]) {
                iscut[u] = 1;    
                bcc_cnt++; 
                bcc[bcc_cnt].clear();
                for (;;) {
                    edge x = S.top(); 
                    S.pop();
                    if (bccno[x.u] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u] = bcc_cnt;
                    } 
                    if (bccno[x.v] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v] = bcc_cnt;
                    } 
                    if (x.u == u && x.v == v) break;
                }
            }
        }
        else if (pre[v] < pre[u] && v != fa) {
            S.push(e); 
            lowu = min(lowu, pre[v]);
        } 
    }
    if (fa < 0 && child == 1) iscut[u] = 0;
    return lowu;
}

void find_bcc() {
    memset(pre, 0, sizeof(pre));
    memset(bccno, 0, sizeof(bccno));
    memset(iscut, 0, sizeof(iscut));
    dfs_clock = bcc_cnt = 0;
    for (int i = 0; i < n; i++)
        if (!pre[i])
            dfs(i, -1);
}

int bipartite(int u, int cur_bccno) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (bccno[v] != cur_bccno) continue;
        if (color[v] == color[u]) return 0;
        if (!color[v]) {
            color[v] = 3 - color[u]; 
            if (!bipartite(v, cur_bccno)) return 0;
        }
    } 
    return 1;
}

int main() {
    while (scanf("%d%d", &n, &m) && (n + m)) {
        for (int i = 0; i < n; i++) g[i].clear();

        memset(map, 0, sizeof(map)); 
        for (int i = 0; i < m; i++) {
            int u, v; 
            scanf("%d%d", &u, &v); 
            u--;
            v--;
            map[u][v] = map[v][u] = 1;
        }
        for (int i = 0; i < n; i++)
            g[i].clear();
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++)
                if (!map[i][j]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }

        find_bcc();
        
        memset(odd, 0, sizeof(odd));
        for (int i = 1; i <= bcc_cnt; i++) {
            memset(color, 0, sizeof(color));
            for (int j = 0; j < bcc[i].size(); j++) 
                bccno[bcc[i][j]] = i;
            int u = bcc[i][0];          
            color[u] = 1; 
            if (!bipartite(u, i))
                for (int j = 0; j < bcc[i].size(); j++)
                    odd[bcc[i][j]] = 1;
        }        

        int ans = n;
        for (int i = 0; i < n; i++)
            if (odd[i])
                ans--;
        printf("%d\n", ans);
    }
    return 0;
}
