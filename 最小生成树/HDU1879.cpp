#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10005

using namespace std;

struct state{
    int l, r, value;
}s[N];

int n, cnt, ans, f[N];

bool cmp(const state& a, const state& b) {
    return a.value < b.value;
}

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

void init() {
    int a, b, c, d;
    int m = n * (n - 1) / 2;
    cnt = ans = 0;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d); 
        if (d == 0) {
            s[cnt].l = a; 
            s[cnt].r = b; 
            s[cnt].value = c;
            cnt++;
        } 
        else
            f[a] = b;
    }
    sort(s, s + cnt, cmp);
}

void kruskal() {
    for (int i = 0; i < cnt; i++) {
        int p = getFather(s[i].l); 
        int q = getFather(s[i].r); 
        if (p != q) {
            ans += s[i].value; 
            f[p] = q; 
        } 
    } 
}

int main() {
    while (scanf("%d", &n) && n) {
        init(); 
        kruskal(); 
        printf("%d\n", ans);
    } 
    return 0;
}

