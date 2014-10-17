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
    bool cut, vis;
}edge[MAXN * 10];

int head[MAXN], tot;
int Low[MAXN], DFN[MAXN];
int Index, top;
int bridge;

vector<pair<int, int> > ans; 

void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].vis = false;
    head[u] = tot++;
}

void Tarjan(int u, int pre) {
    int v;
    Low[u] = DFN[u] = ++Index;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;
        if (v == pre) continue; 
        if (edge[i].vis) continue;
        edge[i].vis = edge[i^1].vis = true;
        ans.push_back(make_pair(u, v));
        if (!DFN[v]) {
            Tarjan(v, u); 
            if (Low[u] > Low[v]) Low[u] = Low[v];
            if (Low[v] > DFN[u]) {
                ans.push_back(make_pair(v, u));
            }
        } 
        else if (Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
}

void init() {
    memset(head, -1, sizeof(head));
    memset(DFN, 0, sizeof(DFN)); 
    tot = Index = 0;
}

int main() {
    int n, m, t = 1; 
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        init();
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v); 
            addedge(u, v); 
            addedge(v, u);  
        }

        ans.clear();
        for (int i = 1; i <= n; i++) {
            if (!DFN[i])
                Tarjan(i, i);
        }

        printf("%d\n\n", t++);
        for (int i = 0; i < ans.size(); i++) 
            printf("%d %d\n", ans[i].first, ans[i].second);
        printf("#\n");
    }
    return 0;
}


