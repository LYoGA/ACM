#include <stdio.h>
#include <string.h>
#define N 50005

int father[N];
int n, m;

void init(int n) {
    for (int i = 0; i < n; i++)
        father[i] = i; 
}

int getParent(int x) {
    if (father[x] != x)
        father[x] = getParent(father[x]);
    return father[x];
}

void Union(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);
    if (pa != pb) {
        father[pa] = getParent(pb); 
        n--;
    } 
}

int main() {
    int t = 0;
    while (scanf("%d %d", &n, &m) && n && m) {
        init(n); 
        int a, b; 
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b); 
            Union(a, b);  
        }
        printf("Case %d: %d\n", ++t, n);
    }
    return 0;
}
