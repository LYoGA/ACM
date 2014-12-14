#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 20010;
const int MAXM = 100010;

struct Edge{
    int to, next;
}edge[MAXM];

int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];
int Index, top;
int scc;
bool Instack[MAXN];
int num[MAXN];
int n, m;

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Tarjan(int u) {
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;         
        if (!DFN[v]) {
            Tarjan(v); 
            if (Low[u] > Low[v]) Low[u] = Low[v];
        } 
        else if (Instack[v] && Low[u] > DFN[v]) 
            Low[u] = DFN[v];
    }
    if (Low[u] == DFN[u]) {
        scc++; 
        do { 
            v = Stack[--top]; 
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        } while (v != u); 
    }
}

void solve() {
    memset(Low, 0, sizeof(Low));
    memset(DFN, 0, sizeof(DFN));
    memset(num, 0, sizeof(num));
    memset(Stack, 0, sizeof(Stack));
    memset(Instack, false, sizeof(Instack));
    Index = scc = top = 0;
    for (int i = 1; i <= n; i++) 
        if (!DFN[i])
            Tarjan(i);
}

vector<int> g[MAXN];
int linker[MAXN], used[MAXN];

bool dfs(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (!used[v]) {
            used[v] = 1; 
            if (linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u; 
                return true;
            }
        } 
    }
    return false;
}

int hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int i = 1; i <= scc; i++) {
        memset(used, 0, sizeof(used)); 
        if (dfs(i)) res++; 
    }
    return scc - res;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &m);         
        init();
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v); 
            addedge(u, v); 
        }
        solve(); 

        for (int i = 0; i <= scc; i++) g[i].clear();
        for (int u = 1; u <= n; u++) {
            for (int i = head[u]; i != -1; i = edge[i].next) {
                int v = edge[i].to;
                if (Belong[u] != Belong[v]) 
                    g[Belong[u]].push_back(Belong[v]);
            }  
        }
        printf("%d\n", hungary()); 
    }
    return 0;
}
