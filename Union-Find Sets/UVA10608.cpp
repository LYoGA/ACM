#include <iostream>
#include <cstdio>
#include <cstring>
#define N 30000

using namespace std;

int cas, n, m, ans;
int father[N], cnt[N];
 
void init(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        cnt[i] = 1;
    }
}

int getFather(int x) {
    return x == father[x] ? x : father[x] = getFather(father[x]);
}

void Union(int a, int b) {
    int pa = getFather(a);
    int pb = getFather(b);
    if (pa != pb) {
        father[pb] = pa;
        cnt[pa] += cnt[pb]; 
    }
    if (cnt[pa] > ans) 
        ans = cnt[pa];
}

int main() {
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d %d", &n, &m); 
        ans = 0;
        init(n); 
        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b); 
            Union(a, b); 
        }
        printf("%d\n", ans);
    }
    return 0;
}
