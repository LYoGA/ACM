#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct Edge{
    int to, next;
    bool cut;
}edge[MAXN * 10];

int head[MAXN], tot;
int Low[MAXN], DFN[MAXN];
int Index, cnt;
bool cut[MAXN];

map<string ,int> name;
map<string, int>::iterator iter;

string s1, s2;

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
    tot = Index = cnt = 0;
    name.clear();
}

void solve(int N) {
    for (int i = 1; i <= N; i++)
        if (!DFN[i])
            Tarjan(i, i);
    for (int i = 1; i <= N; i++)
        if (cut[i]) 
            cnt++; 
}

int main() {
    int n, m, t = 0; 
    while (scanf("%d", &n) && n) {
        init(); 
        for (int i = 1; i <= n; i++) {
            cin >> s1;                
            name[s1] = i;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            cin >> s1 >> s2; 
            addedge(name[s1], name[s2]);
            addedge(name[s2], name[s1]);
        }
        
        solve(n);
        if (t) printf("\n"); 
        printf("City map #%d: %d camera(s) found\n", ++t, cnt);
        for (iter = name.begin(); iter != name.end(); iter++)
            if (cut[iter -> second])
                cout << iter -> first << endl; 
    }
    return 0;
}


