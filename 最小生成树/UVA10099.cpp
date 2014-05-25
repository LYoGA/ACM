#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10005

using namespace std;

struct state{
    int l, r, value;
}s[N];

int n, m, k, t, d, ans1, ans2;
int f[N];

bool cmp(const state& a, const state& b) {
    return a.value > b.value;
}

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

void init() {
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 0; i < m; i++)         
        scanf("%d %d %d", &s[i].l, &s[i].r, &s[i].value);
    scanf("%d %d %d", &k, &t, &d); 
    sort(s, s + m, cmp);
}

int kruskal(int a, int b) {
    for (int i = 0; i < m; i++) {
        int p = getFather(s[i].l); 
        int q = getFather(s[i].r);
        if (p != q) {
            f[p] = q;  
            if (getFather(a) == getFather(b))
                return s[i].value;
        } 
    }
    return 0;
}

int deal(int x) {
    if (d % ans1)
        return d / (ans1 - 1) + 1;
    else
        return d / (ans1 - 1);
}

int main() {
    int cas = 0;
    while (scanf("%d %d", &n, &m) && n && m) {
        init();
        printf("Scenario #%d\n", ++cas);
        ans1 = kruskal(k, t);
        ans2 = deal(d);
        printf("Minimum Number of Trips = %d\n\n", ans2); 
    }    
    return 0;
}
