#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);
const int MAXN = 15;

char g[MAXN][MAXN];
int n;

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%s", g[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == '.')
                    for (char ch = 'A'; ch <= 'Z'; ch++) {
                        bool ok = true; 
                        if (i > 0 && g[i - 1][j] == ch) 
                            ok = false;
                        if (i < n - 1 && g[i + 1][j] == ch) 
                            ok = false;
                        if (j > 0 && g[i][j - 1] == ch) 
                            ok = false;
                        if (j < n - 1 && g[i][j + 1] == ch) 
                            ok = false;
                        if (ok) {
                            g[i][j] = ch; 
                            break; 
                        }
                    }
        printf("Case %d:\n", t++);
        for (int i = 0; i < n; i++)
            printf("%s\n", g[i]);
    } 
    return 0;
}
