#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 105 
using namespace std;

struct state{
    int l, r, v;
}s[N];

int n, ans, t, f[N];

bool cmp(const state& a, const state& b) {
    return a.v < b.v;
}

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

void init() {
    for (int i = 0; i < n; i++)
        f[i] = i;
    int m, cnt, cnt1;
    char ch, ch1; 
    t = 0;
    for (int i = 0; i < n - 1; i++) {
        scanf("%c", &ch); 
        m = ch - 'A'; 
        scanf("%d", &cnt); 
        getchar();
        for (int j = 0; j < cnt; j++) {
            scanf("%c %d", &ch1, &cnt1); 
            getchar();
            s[t].l = m;
            s[t].r = ch1 - 'A';
            s[t].v = cnt1;
            t++;
        }
    }
    sort(s, s + t, cmp);
}

void kruskal() {
    ans = 0;
    for (int i = 0; i < t; i++) {
        int p = getFather(s[i].l); 
        int q = getFather(s[i].r); 
        if (p != q) {
            ans += s[i].v; 
            f[p] = q; 
        } 
    }
}

int main() {
    while (scanf("%d", &n) && n) {
        getchar();
        init(); 
        kruskal(); 
        printf("%d\n", ans);
    }    
    return 0;
}
