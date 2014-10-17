#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

struct Edge{
    int to, next;
}edge[MAXN * 100];

int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], dg[MAXN], used[MAXN];
int Index;
int bridge;

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
            if (Low[u] > Low[v]) 
                Low[u] = Low[v];  
            if (Low[v] > DFN[u])
                bridge++;
        }   
        else if (Low[u] > DFN[v])  
            Low[u] = DFN[v];  
    }  
}

void init() {
    memset(head, -1, sizeof(head));
    memset(DFN, 0, sizeof(DFN)); 
    memset(Low, 0, sizeof(Low)); 
    Index = tot = 0;
    bridge = 0;
}

void solve(int N) {
    for (int i = 1; i <= N; i++)
        if (!DFN[i]) {
            Tarjan(i, i);
            bridge++;
        }

    if (bridge == 1) {
        printf("0\n"); 
    }
    else {
        memset(used, 0, sizeof(used));
        memset(dg, 0, sizeof(dg)); 
        for (int u = 1; u <= N; u++) {
            if (head[u] == -1) {
                used[Low[u]] = 1;
                continue;
            }
            for (int i = head[u]; i != -1; i = edge[i].next) {
                int v = edge[i].to; 
                used[Low[u]] = used[Low[v]] = 1;
                if (Low[u] != Low[v]) {
                    dg[Low[u]]++; 
                }
            }
        }

        int ans = 0;
        for (int u = 1; u <= N; u++) {
            if (used[u] && dg[u] == 0) ans += 2;  
            else if (dg[u] == 1) ans++;  
        }
        ans = (ans + 1) / 2;
        printf("%d\n", ans);
    }
}

int main() {
    int n, m; 
    while (scanf("%d%d", &n, &m) != EOF) {
        init(); 
        int u, v;
        while (m--) {
            scanf("%d%d", &u, &v); 
            addedge(u, v);
            addedge(v, u);
        }
        solve(n);
    }
    return 0;
}

