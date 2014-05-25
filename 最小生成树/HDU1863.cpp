#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int father[105];

struct node{
    int l, r, v;
}p[105];

int cmp(const node &a, const node&b) {
    return a.v < b.v;
}

void init(int n) {
    for (int i = 1; i <= n; i++)
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
    if (pa == pb) return;
    if (pa > pb) 
//        father[a] = b;
        father[pa] = getParent(pb);
    else
        //father[b] = a;
        father[pb] = getParent(pa);
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        init(n); 
        for (int i = 0; i < m; i++) 
            scanf("%d %d %d", &p[i].l, &p[i].r, &p[i].v); 
        sort(p, p + m, cmp);  
        int w = 0, sum = 0; 
       for (int i = 0; i < m; i++) {
            if (getParent(p[i].l) != getParent(p[i].r)) {
                Union(p[i].l, p[i].r); 
                sum += p[i].v;
            }             
        } 
        w = getParent(p[0].l);
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            if (getParent(i) != w) {
                flag = 0;  
                break; 
            } 
        }
        if (flag)
            printf("%d\n", sum);
        else
            printf("?\n"); 
    } 
        return 0;
}
