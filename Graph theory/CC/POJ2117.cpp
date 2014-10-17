#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct Edge{
    int to, next;
    bool cut;
}edge[MAXN * 10];

int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN];
int Index, cnt;
bool Instack[MAXN];
bool cut[MAXN];
int add_block[MAXN];

void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].cut = false;
    head[u] = tot++;
}

void Tarjan(int u, int pre) {
    int v;
    Low[u] = DFN[u] = ++Index;
    int son = 0;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;
        if (v == pre) continue; 
        if (!DFN[v]) {
            son++; 
            Tarjan(v, u); 
            if (Low[u] > Low[v]) 
                Low[u] = Low[v];
            if (u != pre && Low[v] >= DFN[u]) {
                cut[u] = true; 
                add_block[u]++;
            }
        } 
        else if (Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if (u == pre && son > 1) cut[u] = true;
    if (u == pre) add_block[u] = son - 1;
}

void init() {
    memset(head, -1, sizeof(head));
    memset(DFN, 0, sizeof(DFN)); 
    memset(add_block, 0, sizeof(add_block)); 
    memset(cut, false, sizeof(cut)); 
    tot = Index = cnt = 0;
}

void solve(int N) {
    for (int i = 1; i <= N; i++)
        if (!DFN[i]) {
            Tarjan(i, i);
            cnt++;
        }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, cnt + add_block[i]);
    printf("%d\n", ans);
}

int main() {
    int n, m; 
    while (scanf("%d%d", &n, &m) == 2) {
        if (n == 0 && m == 0) break;
        init(); 
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v); 
            u++;
            v++;
            addedge(u, v);
            addedge(v, u);
        } 
        solve(n);
    }
    return 0;
}


