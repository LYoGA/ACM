#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 20100;
const int MAXM = 50100;
const int INF = 0x3f3f3f3f;

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
int cost[MAXN];
int in[MAXN];

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
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        for (int i = 1; i <= n; i++) 
            scanf("%d", &cost[i]);
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v); 
            addedge(u, v);
        } 
        solve(); 

        memset(in, 0, sizeof(in));
        for (int u = 1; u <= n; u++) {
            for (int i = head[u]; i != -1; i = edge[i].next) {
                int v = edge[i].to; 
                if (Belong[u] != Belong[v]) {
                    in[Belong[v]]++;
                } 
            } 
        }
        int ans = 0, num = 0, tmp;
        for (int i = 1; i <= scc; i++) {
            tmp = INF; 
            if (in[i] == 0) {
                for (int u = 1; u <= n; u++) {
                    if (Belong[u] == i)
                        tmp = min(tmp, cost[u]);
                }  
                ans += tmp;
                num++;
            }  
        }
        printf("%d %d\n", num, ans);
    } 
    return 0;
}
