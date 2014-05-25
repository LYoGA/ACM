#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100005

using namespace std;

struct state{
    int l, r, value;
}s[N];

int n, m, cnt;
int f[N], sum;

bool cmp(const state& a, const state& b) {
    return a.value > b.value; 
}

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

void init() {
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) 
        f[i] = i;          
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &s[i].l, &s[i].r, &s[i].value);
    sort(s, s + m, cmp);
    cnt = sum = 0;
}

int kruskal() {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int p = getFather(s[i].l); 
        int q = getFather(s[i].r); 
        if (p != q) {
            f[p] = q;
            sum += s[i].value;
            cnt++;
        }
    }
    return sum;
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        init(); 
        int ans = kruskal();
        if (cnt == n - 1)
            printf("%d\n", ans);
        else
            printf("-1\n"); 
    }
    return 0;
}
