#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 5610;

struct turtle{
    int w, s;
}t[MAXN];

int d[MAXN];
int cnt = 1;

int cmp(turtle a, turtle b) {
    if (a.s != b.s)
        return a.s < b.s;
    else if (a.s == b.s)
        return a.w < b.w;
}

void init() {
    sort(t + 1, t + cnt, cmp); 
    for (int i = 1; i < cnt; i++)
        d[i] = INF;
    d[0] = 0;
}

int main() {
    while (scanf("%d %d", &t[cnt].w, &t[cnt].s) != EOF) 
        cnt++; 
    init();

    int Max = 0;
    for (int i = 1; i < cnt; i++) {
        for (int j = cnt - 1; j >= 1; j--) {
            if (d[j - 1] + t[i].w <= t[i].s) 
                d[j] = min(d[j], d[j - 1] + t[i].w);
            if (d[j] < INF) 
                Max = max(j, Max);
        }
    }
    printf("%d\n", Max);
    return 0;
}
