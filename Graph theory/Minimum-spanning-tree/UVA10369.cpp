#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 250005

using namespace std;

struct state{
    int l, r;
    double value;
}s[N];

int n, m, cnt, f[N], x[N], y[N];
double ans;

bool cmp(const state& a, const state& b) {
    return b.value - a.value > 1e-9;
}

int getFather(int x) {
    x == f[x] ? x : f[x] = getFather(f[x]); 
}

void init() {
    cnt = 0;
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    scanf("%d %d", &n, &m); 
    for (int i = 0; i < m; i++) {
        f[i] = i;
        scanf("%d %d", &x[i], &y[i]); 
        for (int j = 0; j < i; j++) {
            s[cnt].value = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])); 
            s[cnt].l = i; 
            s[cnt].r = j; 
            cnt++;
        }     
    }
    sort(s, s + cnt, cmp);
}

void kruskal() {
    int t = m - n - 1;
    for (int i = 0; i < cnt; i++) { 
        int p = getFather(s[i].l);
        int q = getFather(s[i].r); 
        if (p != q) {
            ans = s[i].value;
            if (t) {
                t--; 
                f[q] = p; 
            }
            else
                return;
        } 
    }
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init();  
        kruskal(); 
        printf("%.2lf\n", ans);
    }
    return 0;
}

