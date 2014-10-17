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
int Index, top;
bool Instack[MAXN];
bool cut[MAXN];
int add_block[MAXN];
int bridge;

void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].cut = false;
    head[u] = tot++;
}

void Tarjan(int u, int pre) {
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    int son = 0;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;
        if (v == pre) continue; 
        if (!DFN[v]) {
            son++; 
            Tarjan(v, u); 
            if (Low[u] > Low[v]) Low[u] = Low[v];
            if (Low[v] > DFN[u]) {
                bridge++; 
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
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
    Instack[u] = false;
    top--;
}

void init() {
    memset(head, -1, sizeof(head));
    memset(DFN, 0, sizeof(DFN)); 
    memset(Instack, false, sizeof(Instack)); 
    memset(add_block, 0, sizeof(add_block)); 
    memset(cut, false, sizeof(cut)); 
    tot = 0;
    Index = top = 0;
    bridge = 0;
}

void solve(int N) {
    for (int i = 1; i <= N; i++)
        if (!DFN[i])
            Tarjan(i, i);

    printf("%d critical links\n",bridge);
    vector<pair<int, int> > ans; 
    for (int u = 1; u <= N; u++) 
        for (int i = head[u]; i != -1; i = edge[i].next) 
            if (edge[i].cut && edge[i].to > u) {
                ans.push_back(make_pair(u, edge[i].to)); 
            }

   sort(ans.begin(), ans.end()); 
   for(int i = 0;i < ans.size();i++)
       printf("%d - %d\n",ans[i].first-1,ans[i].second-1);
   printf("\n");
}

int main() {
    int n; 
    while (scanf("%d", &n) == 1) {
        init(); 
        int u, k, v;     
        for (int i = 1; i <= n; i++) {
            scanf("%d (%d)", &u, &k); 
            u++;
            while (k--) {
                scanf("%d", &v); 
                v++; 
                addedge(u, v);
                addedge(v, u);
            }
        }
        solve(n);
    }
    return 0;
}


