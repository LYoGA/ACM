#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 305;

vector<int> g[MAXN];
int n, color[MAXN];

void init() {
    for (int i = 0; i < n; i++) 
        g[i].clear();
}

bool bipartite(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (color[u] == color[v]) return false; 
        if (!color[v]) {
            color[v] = 3 - color[u];
            if (!bipartite(v)) return false;
        }
    }
    return true;
}

int main() {
    while (scanf("%d", &n) && n) {
        init();
        int u, v; 
        while (scanf("%d%d", &u, &v)) {
            if (u == 0 && v == 0)
                break;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        memset(color, 0, sizeof(color));
        color[0] = 1;  
        if(bipartite(0))  
            printf("YES\n");  
        else  
            printf("NO\n");  
    } 
    return 0;
}
