#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

vector<int> g[MAXN];
int linker[MAXN];
bool used[MAXN];
int n, m;

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

int save[MAXN];

int hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 1; u <= n; u++) {
        memset(used, false, sizeof(used)); 
        if (dfs(u)) res++;
    }
    return res;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) g[i].clear();

        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }
        printf("%d\n", n - hungary());
    }
    return 0;
}
