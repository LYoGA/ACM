#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005

using namespace std;

int f[N * 2], cnt[N * 2], sum[N * 2];
int n, m, a, b, k;

void init() {
    for (int i = 1; i <= n; i++) {
        f[i] = i + n;
        f[i + n] = i + n;
        sum[i + n] = i; 
        cnt[i + n] = 1;
    }
}

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

void Delete(int a, int b) {
    int pa = getFather(a);
    int pb = getFather(b);
    if (pa != pb) {
        f[a] = getFather(pb); 
        sum[pa] -= a;
        sum[pb] += a;
        cnt[pa]--; 
        cnt[pb]++;
    }
}

void Union(int a, int b) {
    int pa = getFather(a);
    int pb = getFather(b);
    if (pa != pb) {
        f[pa] = getFather(pb); 
        sum[pb] += sum[pa]; 
        cnt[pb] += cnt[pa]; 
    }
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        init(); 
        for (int i = 0; i < m; i++) {
            scanf("%d", &k); 
            if (k == 1) {
                scanf("%d %d", &a, &b);
                Union(a, b);
            }   
            else if (k == 2) {
                scanf("%d %d", &a, &b);
                Delete(a, b); 
            } 
            else if (k == 3) {
                scanf("%d", &a); 
                int pa = getFather(a); 
                printf("%d %d\n", cnt[pa], sum[pa]); 
            }
        } 
    }
    return 0;
}
