#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct work{
    char name[50];
    int a, b, cost;
}p[105];

int cmp(const work &a, const work &b) {
    if (a.cost != b.cost)
        return a.cost < b.cost;
    return strcmp(a.name, b.name) < 0;
}

int main () {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        int M, N, L;
        char s[50];
        scanf("%d %d %d", &N, &M, &L);
        for (int i = 0; i < L; i++) {
            scanf("%s", s);
            sscanf(s, "%[^:]:%d,%d", p[i].name, &p[i].a, &p[i].b);
            p[i].cost = 0; 
        } 
        for (int i = 0; i < L; i++) {
            int h = N;
            int n = p[i].a, m = p[i].b;
            int half = (h + 1) / 2;
            while (h - half >= M && (h - half) * n >= m) {
                p[i].cost += m; 
                h -= half;
                half = (h + 1) / 2;
            } 
            if (h > M)
                p[i].cost += (h - M) * n;
        }
        sort(p, p + L, cmp);
        printf("Case %d\n", t++);
        for (int i = 0; i < L; i++)
            printf("%s %d\n", p[i].name, p[i].cost);
    }
    return 0;
}

