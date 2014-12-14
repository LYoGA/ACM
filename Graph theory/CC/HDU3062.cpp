#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct TwoSAT{
    int n;
    vector<int> g[MAXN * 2];
    bool mark[MAXN * 2];
    int s[MAXN * 2], c;

    bool dfs(int x) {
        if (mark[x^1]) return false;
        if (mark[x]) return true;
        mark[x] = true;
        s[c++] = x;
        for (int i = 0; i < g[x].size(); i++)
            if (!dfs(g[x][i])) return false;
        return true;
    }

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n * 2; i++) 
            g[i].clear();
        memset(mark, 0, sizeof(mark));
        mark[1] = 1;
    }

    void add_clause(int x, int xval, int y, int yval) {
        x = x * 2 + xval;
        y = y * 2 + yval;
        g[x^1].push_back(y);
        g[y^1].push_back(x);
    }

    bool solve() {
        for (int i = 0; i < n * 2; i += 2) 
            if (!mark[i] && !mark[i + 1]) {
                c = 0;
                if (!dfs(i)) {
                    while (c > 0) mark[s[--c]] = false; 
                    if (!dfs(i + 1)) return false;
                }
            }
        return true;
    }
};

TwoSAT solver;

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        solver.init(n);
        scanf("%d", &m); 
        int u, v, a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d%d", &u, &v, &a, &b);
            solver.add_clause(u, a, v, b);
        }
        if (solver.solve())
            printf("YES\n");
        else
            printf("NO\n"); 
    }
    return 0;
}

