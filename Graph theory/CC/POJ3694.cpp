#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

struct Edge{
    int to, next;
}edge[MAXN * 5];
int head[MAXN], tot;
int Low[MAXN], DFN[MAXN];
int Index, top;
int bridge;
int n, m;
int f[MAXN], ancestor[MAXN];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

bool Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) {
        f[pa] = pb;
        return true;
    }
    return false;
}

void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Tarjan(int u, int pre) {
    int v;
    Low[u] = DFN[u] = ++Index;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;
        if (v == pre) continue; 
        if (!DFN[v]) {
            Tarjan(v, u); 
            ancestor[v] = u;
            if (Low[u] > Low[v]) Low[u] = Low[v];
            if (Low[v] > DFN[u]) 
                bridge++;  
            else 
                Union(u, v);
        } 
        else if (Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
}

void init() {
    memset(head, -1, sizeof(head));
    memset(DFN, 0, sizeof(DFN)); 
    tot = 0;
    Index = top = 0;
    bridge = 0;
    memset(ancestor, 0, sizeof(ancestor));
    for (int i = 1; i <= n; i++)
        f[i] = i;
}

void solve() {
    for (int i = 1; i <= n; i++)
        if (!DFN[i])
            Tarjan(i, -1);
}

void lca(int u, int v) {
    while (u != v) {
        while (DFN[u] >= DFN[v] && u != v) {
            if (Union(u, ancestor[u]))  
                bridge--;
            u = ancestor[u];
        }
        while (DFN[v] >= DFN[u] && u != v) {
            if (Union(v, ancestor[v]))  
                bridge--;
            v = ancestor[v];
        }
    }
}

int main() {
    int t = 1;
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        init(); 
        int u, v;  
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v); 
            addedge(u, v);
            addedge(v, u);
        }
        solve();

        printf("Case %d:\n", t++);
        int k;
        scanf("%d", &k);
        while (k--) {
            scanf("%d%d", &u, &v); 
            lca(u, v);
            printf("%d\n", bridge);
        }
        printf("\n");
    }
    return 0;
}


