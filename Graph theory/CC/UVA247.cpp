#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 2000;
const int MAXM = 50000;

struct Edge{
    int to, next;
}edge[MAXM];

int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];
int Index, top;
int scc;
bool Instack[MAXN];
int num[MAXN];
int n, m, cnt;
map<string, int> sTon;
map<int, string> nTos; 

void init() {
    tot = cnt = 0;
    memset(head, -1, sizeof(head));
    sTon.clear();
    nTos.clear();
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
    memset(Belong, 0, sizeof(Belong));
    memset(Stack, 0, sizeof(Stack));
    memset(Instack, false, sizeof(Instack));
    Index = scc = top = 0;
    for (int i = 1; i <= n; i++) 
        if (!DFN[i])
            Tarjan(i);
}

int main() {
    int t = 0;
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break; 
        init();
        string s1, s2;   
        for (int i = 0; i < m; i++) {
            cin >> s1 >> s2;  
            if (sTon.find(s1) == sTon.end()) {
                cnt++; 
                sTon[s1] = cnt;
                nTos[cnt] = s1;
            }     
            if (sTon.find(s2) == sTon.end()) {
                cnt++; 
                sTon[s2] = cnt;
                nTos[cnt] = s2;
            }     
            addedge(sTon[s1], sTon[s2]);
        }

        if (t) printf("\n");  
        printf("Calling circles for data set %d:\n", ++t);
        solve();
        for (int i = 1; i <= scc; i++) {
            int flag = 0;
            for (int u = 1; u <= n; u++) {
                if (Belong[u] == i) {
                    if (!flag) {
                        cout << nTos[u];
                        flag = 1;
                    }
                    else cout << ", " << nTos[u];
                }
            }              
            printf("\n");
        }
    } 
    return 0;
}

