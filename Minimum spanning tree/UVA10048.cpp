#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10005

using namespace std;

struct state{
    int l, r, value;
}s[N];

int n, m, f[N];

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

bool cmp(const state& a, const state& b) {
    return a.value < b.value;
}

void init() {
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &s[i].l, &s[i].r, &s[i].value);
    sort(s, s + m, cmp);
}

int kruskal() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 0; i < m; i++) {
        int p = getFather(s[i].l); 
        int q = getFather(s[i].r); 
        if (p != q) {
            f[p] = q; 
            if (getFather(a) == getFather(b))
                return s[i].value;
        }
    }
    return -1;
}

int main() {
    int cas = 0, q;
    while (scanf("%d %d %d", &n, &m, &q), n || m || q) {
        init(); 
        if (cas) printf("\n"); 
        printf("Case #%d\n", ++cas);
        for (int i = 0; i < q; i++) {
            int ans = kruskal(); 
            if (ans < 0)
                printf("no path\n");
            else
                printf("%d\n", ans); 
        }
    } 
    return 0;
}
