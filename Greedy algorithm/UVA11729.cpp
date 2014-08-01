#include <algorithm>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

struct person{
    int b, j;
}p[MAXN];

int cmp(person a, person b) {
    return a.j > b.j;
}

int main() {
    int n, t = 1;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) 
            scanf("%d %d", &p[i].b, &p[i].j); 
        sort(p, p + n, cmp); 
        int ans = 0, s = 0;
        for (int i = 0; i < n; i++) {
            s += p[i].b;  
            ans = max(ans, s + p[i].j);
        }
        printf("Case %d: %d\n", t++, ans);
    }
    return 0;
}
