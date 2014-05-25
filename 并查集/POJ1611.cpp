#include <stdio.h>
#define N 30003

int father[N], num[N];
int n, m;

void init(int n) {
    for (int i = 0; i < n; i++) {
        father[i] = i;
        num[i] = 1;
    } 
}

int getParent(int x) {
    if (father[x] != x)
        father[x] = getParent(father[x]);
    return father[x];
}

void Union(int a, int b) {
    int pa = getParent(a); 
    int pb = getParent(b);
    if (pa == pb) return;
    if (num[pa] <= num[pb]) {
        father[pa] = pb;
        num[pb] += num[pa];
    }
    else {
        father[pb] = pa;
        num[pa] += num[pb]; 
    } 
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF && n) {
        init(n); 
        for (int i = 0; i < m; i++) {
            int count, f, s; 
            scanf("%d %d", &count, &f); 
            for (int j = 1; j < count; j++) {
                scanf("%d", &s); 
                Union(f, s); 
            } 
        } 
        printf("%d\n", num[getParent(0)]);  
    }
    return 0;
}



