#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

struct gate{
    double x, y;
}g[MAXN];

int w, v, n, s;
int sv[MAXN];

int judge(int mid) {
    double ss = sv[mid]; 
    double l = g[n - 1].x;  
    double r = g[n - 1].x + w;
    for (int i = n - 2; i >= 0; i--) {
        l -= (v * (g[i + 1].y - g[i].y) / ss);
        r += (v * (g[i + 1].y - g[i].y) / ss);
        if (l < g[i].x)
            l = g[i].x;
        if (r > g[i].x + w)
            r = g[i].x + w;
        if (r < l) {
            return false;
        }
    } 
    return true;
}

int main() {

    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &w, &v, &n);                 
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &g[i].x, &g[i].y); 
        scanf("%d", &s);
        for (int i = 0; i < s; i++)
            scanf("%d", &sv[i]);
        sort(sv, sv + s);

        int L = -1, R = s, mid;
        while (L < R - 1) {
            mid = L + (R - L) / 2; 
            if (judge(mid))
                L = mid;
            else
                R = mid;
        }
        if (L == -1) 
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", sv[L]);
    }
    return 0;
}
