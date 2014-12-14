#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 510;
int linker[MAXN];
bool used[MAXN];

vector<int> g[MAXN];
int n;

bool dfs(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (!used[v]) {
            used[v] = true; 
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
    for (int u = 0; u < n; u++) {
        memset(used, false, sizeof(used)); 
        if (dfs(u))
            res++;
    }
    return res;
}

int main() {
    while (scanf("%d", &n) != EOF) {  
        for (int i = 0; i < n; i++) g[i].clear();  
        int u, cnt, v;  
        for (int i = 0; i < n; i++) {  
            scanf("%d: (%d)", &u, &cnt);  
            while (cnt--) {  
                scanf("%d", &v);  
                g[u].push_back(v);  
            }  
        }  
        printf("%d\n", n - hungary() / 2);  
    }  
    return 0;
}

