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
int r, c;

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

void hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 1; u <= r; u++) {
        memset(used, false, sizeof(used)); 
        if (dfs(u)) res++;
    }
    if (res != r) {
        printf("NO\n");  
        return;
    }
    for (int i = 1; i <= c; i++) 
        printf("%d%c", linker[i] != -1 ? linker[i] : save[i], i == c ? '\n' : ' '); 
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &r, &c); 
        for (int i = 1; i <= r; i++) g[i].clear();

        int pos;  
        for (int i = 1; i <= c; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%d", &pos); 
                save[i] = pos;
                g[pos].push_back(i);
            }
        }
        hungary();
    }
    return 0;
}
