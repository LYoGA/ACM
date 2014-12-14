#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5005;

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
    while (scanf("%d%d", &n, &m) != EOF) {
        solver.init(n * 3); 
        int a, b, c;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            solver.add_clause(a, 1, b, 1);
            solver.add_clause(a, 1, c, 1);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            solver.add_clause(a, 0, b, 0); 
        }

        if (solver.solve()) 
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

