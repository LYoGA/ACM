#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 10005

using namespace std;

struct state{
    int l, r;
    double value;
}s[N];

int n, cnt, f[N];
double sum, x[N], y[N];

bool cmp(const state& a, const state& b) {    
    return b.value - a.value > 1e-9;
}

int getFather(int x) {
    return x == f[x] ? x : x = getFather(f[x]);
}

void init() {
    cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        f[i] = i;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]); 
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
    sum = 0;
    for (int i = 0; i < cnt; i++) {
        int p = getFather(s[i].l); 
        int q = getFather(s[i].r); 
        if (p != q) {
            f[p] = q; 
            sum += s[i].value;
        } 
    }
    return;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init(); 
        kruskal(); 
        printf("%.2lf\n", sum);
        if (cas)
            printf("\n");
    } 
    return 0;
}

