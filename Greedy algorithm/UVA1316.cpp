#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct product{
    int money, t;
}p[MAXN];

int n, vis[MAXN];

int cmp(product a, product b) {
    return a.money > b.money;
}

int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)  
            scanf("%d%d", &p[i].money, &p[i].t); 


        sort(p, p + n, cmp); 
        memset(vis, 0, sizeof(vis));
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = p[i].t; j >= 1; j--) {
                if (vis[j] == 0) {
                    ans += p[i].money;
                    vis[j] = 1; 
                    break;
                }
            }  
        }
        cout << ans << endl;
    }
    return 0;
}
