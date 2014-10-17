#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 105;

vector<int> g[MAXN];
stack<int> s; 
int pre[MAXN], lowlink[MAXN], sccno[MAXN], dfs_clock, scc_cnt;
int n, in[MAXN], out[MAXN];

void tarjan(int u) {
    pre[u] = lowlink[u] = ++dfs_clock; 
    s.push(u);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (!pre[v]) {
            tarjan(v); 
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!sccno[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u]) {
        scc_cnt++; 
        int x = -1;
        while (x != u) {
            x = s.top(); 
            s.pop();
            sccno[x] = scc_cnt;
        }
    }
}

void find_scc() {
    memset(pre, 0, sizeof(pre));
    memset(sccno, 0, sizeof(sccno));
    memset(lowlink, 0, sizeof(lowlink));
    dfs_clock = scc_cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!pre[i])
            tarjan(i);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        int u;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            while (scanf("%d", &u) && u) 
                g[i].push_back(u);
        }

        find_scc();
        if (scc_cnt == 1) {
            printf("1\n0\n"); 
            continue;
        }
        else {
            memset(in, 0, sizeof(in)); 
            memset(out, 0, sizeof(out)); 
            for (int u = 1; u <= n; u++) {
                for (int i = 0; i < g[u].size(); i++) {
                    int v = g[u][i]; 
                    if (sccno[u] != sccno[v]) {
                        in[sccno[v]]++;  
                        out[sccno[u]]++;
                    }
                }  
            } 
            int a = 0, b = 0;
            for (int i = 1; i <= scc_cnt; i++) {
                if (in[i] == 0) a++; 
                if (out[i]== 0) b++;  
            }
            int ans = max(a, b);
            printf("%d\n%d\n", a, ans);
        }
    } 
    return 0;
}
