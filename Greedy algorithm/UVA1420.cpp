#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

struct wedding{
    long long s, t, mid, l;
}w[MAXN];

int n, flag;

int cmp(wedding a, wedding b) {
    return a.mid < b.mid;
}

int solve() {
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (start > w[i].t - w[i].l)
            return false;
        else if (start <= w[i].s)
            start = w[i].mid;
        else 
            start += w[i].l;
    } 
    return true;
}

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &w[i].s, &w[i].t); 
            w[i].l = (w[i].t - w[i].s) / 2 + 1;
            w[i].mid = w[i].s + w[i].l;
        }  
        sort(w, w + n, cmp);
        solve();
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");
    }    
    return 0;
}
