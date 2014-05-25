#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 10005;
const int M = 100005;

struct edge{
    int x, y;
}e[M];

int n, m, cnt, k;
int f[N], num[N];

void init() {
    for (int i = 0; i < n; i++)
       f[i] = i;
    cnt = n;
    k = 0;
}

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]); 
} 

void Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) {
        f[pa] = pb;
        num[k++] = cnt--;
        return;
    }
    num[k++] = cnt;
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        init();        
        for (int i = 0; i < m; i++) 
            scanf("%d %d", &e[i].x, &e[i].y); 
        for (int i = m - 1; i >= 0; i--) 
            Union(e[i].x, e[i].y); 
        for (int i = k - 1; i >= 0; i--)
            printf("%d\n", num[i]);         
    }
    return 0;
}
