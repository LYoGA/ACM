#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 65540;

struct tape{
    int id, l;
    double f, k;
}t[MAXN];

int n, p;

int cmp(tape a, tape b) {
    return a.k > b.k;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d%lf", &t[i].id, &t[i].l, &t[i].f); 
            t[i].k = t[i].f / t[i].l;
        }
        scanf("%d", &p);
        sort(t, t + n, cmp);
        printf("%d\n", t[p - 1].id);
    }
    return 0;
}
