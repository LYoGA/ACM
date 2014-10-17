//DFS框架
vector<int> g[MAXN];
int vis[MAXN];

void dfs(int u) {
    vis[u] = 1;
    PREVISIT(u);
    int d = g[u].size();
    for (int i = 0; i < d; i++) {
        int v = g[u][i]; 
        if (!vis[v]) dfs(v);
    }
    POSTVISIT(u);
}

//无向图连通分量
void find_cc() {
    current_cc = 0;
    memset(vis, 0, sizeof(vis));
    for (int u = 0; u < n; u++)
        if (!vis[u]) {
            current__cc++; 
            dfs(u);
        }
}

//判断结点u所在的连通分量是否为二分图，用黑白染色
int color[MAXN];

bool bipartite(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (color[v] == color[u]) return false;
        if (!color[v]) {
            color[v] = 3 - color[u]; 
            if (!bipartite[v]) return false;
        }
    }
    return true;
}

//无向图的割顶
int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (!pre[v]) {
            child++; 
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u])
                iscut[u] = true;
        }  
        else if (pre[v] < pre[u] && v != fa)
            lowu = min(lowu, pre[v]);
    }
    if (fa < 0 && child == 1) iscut[u] = 0;
    low[u] = lowu;
    return lowu;
}

//计算点-双连通分量
int pre[MAXN], iscut[MAXN], bccno[MAXN], dfs_clock, bcc_cnt;
vector<int> g[MAXN], bcc[MAXN]
stack<Edge> S;

int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock;
    int chile = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        Edge e = (Edge)(u, v);
        if (!pre[v]) {
            S.push(e); 
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u]) {
                iscut[u] = true;      
                bcc_cnt++; 
                bcc[bcc_cnt].clear();
                for (;;) {
                    Edge x = S.top(); 
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

void find_bcc(int n) {
    memset(pre, 0, sizeof(pre));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    dfs_clock = bcc_cnt = 0;
    for (int i = 0; i < n; i++)
        if (!pre[i])
            dfs(i, -1);
}

//SCC的Kosaraju算法
vector<int> g[MAXN], g2[MAXN];
vector<int> s;
int vis[MAXN], sccno[MAXN], scc_cnt;

void dfs1(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++) 
        dfs1(g[u][i]);
    s.push_back(u);
}

void dfs2(int u) {
    if (sccno[u]) return;
    sccno[u] = scc_cnt;
    for (int i = 0; i < g2[u].size(); i++)
        dfs2(g2[u][i]);
}

void find_scc(int n) {
    scc_cnt = 0;
    s.clear();
    memset(sccno, 0, sizeof(sccno));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) dfs1(i);
    for (int i = n - 1; i >= 0; i--)
        if (!sccno[i]) {
            scc_cnt++; 
            dfs2(s[i]);
        }
}

//SCC的Tarjan算法
vector<int> g[MAXN];
int pre[MAXN], lowlink[MAXN], sccno[MAXN], dfs_clock, scc_cnt;
stack<int> s;

void dfs(int u) {
    pre[u] = lowlink[u] = ++dfs_clock;
    s.push(u);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];  
        if (!pre[v]) {
            dfs(v); 
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

void find_scc(int n) {
    dfs_clock = scc_cnt = 0;
    memset(sccno, 0, sizeof(sccno));
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < n; i++)
        if (!pre[i])
            dfs(i);
}

//2-SAT问题
struct TwoSAT{
    int n;
    vector<int> g[MAXN * 2];
    bool mark[MAXN * 2];
    int s[MAXN * 2], c;

    bool dfs(int x) {
        if (mark[x^1]) return false;
        if (mark[x]) return true;
        mark[x] = true;
        s[c++] = x;
        for (int i = 0; i < g[x].size(); i++)
            if (!dfs(g[x][i])) return false;
        return true;
    }

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n * 2; i++) 
            g[i].clear();
        memset(mark, 0, sizeof(mark));
    }

    void add_clause(int x, int xval, int y, int yval) {
        x = x * 2 + xval;
        y = y * 2 + yval;
        g[x^1].push_back(y);
        g[y^1].push_back(x);
    }

    bool solve() {
        for (int i = 0; i < n * 2; i += 2) 
            if (!mark[i] && !mark[i + 1]) {
                c = 0;
                if (!dfs(i)) {
                    while (c > 0) mark[s[--c]] = false; 
                    if (!dfs(i + 1)) return false;
                }
            }
        return true;
    }
};




