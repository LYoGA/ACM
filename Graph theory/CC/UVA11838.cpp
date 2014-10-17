#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2005;
const int MAXM = MAXN * MAXN;

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

int main() {
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        init();
        int u, v, p;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &p); 
            if (p == 1) addedge(u, v);
            if (p == 2) {
                addedge(u, v); 
                addedge(v, u); 
            } 
        }

        solve();
        if (scc == 1) printf("1\n");
        else printf("0\n");
    }    
    return 0;
}
