#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 200;
const int M = 400000;

using namespace std;

struct state{
    int l, r;
    double v;
}s[M];

int n, cnt, t, f[N];
double sum, x[N], y[N];

bool cmp(const state& a, const state& b) {
    return a.v < b.v;
}

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

void init() {
    cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        f[i] = i;
    for (int i = 0; i < n; i++) 
        scanf("%lf %lf", &x[i], &y[i]);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double dis; 
            dis = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            if (dis >= 10 && dis <= 1000) {
                s[cnt].l = i;
                s[cnt].r = j;
                s[cnt].v = dis;
                cnt++;
            }
        }
    }
    sort(s, s + cnt, cmp);
}

void kruskal() {
    t = 1;
    sum = 0;
    for (int i = 0; i < cnt; i++) {
        int p = getFather(s[i].l);
        int q = getFather(s[i].r);
        if (p != q) {
            t++;
            f[p] = q;
            sum += s[i].v;
        }
    }
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init();
        kruskal();
        if (t == n) 
            printf("%.1lf\n", sum * 100);
        else
            printf("oh!");
    }
    return 0;
}
