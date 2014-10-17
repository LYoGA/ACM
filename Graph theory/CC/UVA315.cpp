#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

struct Edge{
    int to, next;
    bool cut;
}edge[MAXN * 10];
int head[MAXN], tot;
int Low[MAXN], DFN[MAXN];
int Index, cnt;
bool cut[MAXN];

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
            if (Low[u] > Low[v]) Low[u] = Low[v];
            if (u != pre && Low[v] >= DFN[u]) {
                cut[u] = true; 
            }
        } 
        else if (Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if (u == pre && son > 1) cut[u] = true;
}

void init() {
    memset(head, -1, sizeof(head));
    memset(DFN, 0, sizeof(DFN)); 
    memset(cut, false, sizeof(cut)); 
    tot = 0;
    Index = cnt = 0;
}

int main() {
    int n; 
    while (scanf("%d", &n) && n) {
        init(); 
        int u, v;
        while (scanf("%d", &u) && u) {
            char ch;
            while (scanf("%d%c", &v, &ch)) {
                addedge(u, v); 
                addedge(v, u); 
                if (ch == '\n') break;
            }            
        }

        for (int i = 1; i <= n; i++)
            if (!DFN[i])
                Tarjan(i, i);
        for (int i = 1; i <= n; i++)
            if (cut[i])
                cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}


