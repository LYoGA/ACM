nclude <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 600005

using namespace std;

struct state{
    int l, r; 
    double value; 
}s[N];

int n, m, cnt, f[N], x[N], y[N];
double sum;

bool cmp(const state& a, const state& b) {
    return a.value < b.value;
}

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

void init() {
    cnt = 0; 
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]); 
        for (int j = 1; j < i; j++) {
            s[cnt].value = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            s[cnt].l = i; 
            s[cnt].r = j;  
            cnt++;
        }
    }
    sort(s, s + cnt, cmp);
    int m, a, b;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b); 
        int p = getFather(a); 
        int q = getFather(b);
        if (p != q) 
            f[p] = q;  
    }
}

void kruskal() {
    sum = 0;
    for (int i = 0; i < cnt; i++) {
        int p = getFather(s[i].l); 
        int q = getFather(s[i].r); 
        if (p != q) {
            sum += s[i].value;
            f[p] = q; 
        } 
    }
    return;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        init(); 
        kruskal();    
        printf("%.2lf\n", sum);
    }
    return 0;
}
