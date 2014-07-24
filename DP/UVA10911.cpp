#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1 << 21;

struct node{
    int x, y;
}t[MAXN];

int n;
char name[MAXN];
double d[MAXN];

double dis(int a, int b) {
    return sqrt((t[a].x - t[b].x) * (t[a].x - t[b].x) + (t[a].y - t[b].y) * (t[a].y - t[b].y)); 
}

int main() {
    int cas = 1;
    while (scanf("%d", &n) && n) {
        int num = n * 2;
        for (int i = 0; i < num; i++) 
            scanf("%s %d %d", name, &t[i].x, &t[i].y);

        d[0] = 0;
        for (int S = 1; S < (1 << num); S++) {
            int i, j;
            d[S] = INF; 
            for (i = 0; i < num; i++) 
                if (S & (1 << i))
                    break;
            for (j = i + 1; j < num; j++)
                if (S & (1 << j))
                    d[S] = min(d[S], d[S ^ (1 << i) ^ (1 << j)] + dis(i, j)); 
        }
        printf("Case %d: %.2lf\n", cas++, d[(1 << num) - 1]); 
    }    
    return 0;
}
