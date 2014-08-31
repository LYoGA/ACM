#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef __int64 ll; 
//typedef long long ll; 
const int MAXN = 100005;

int a[MAXN], b[MAXN], c[MAXN], vis[MAXN];
int n;

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++) 
            scanf("%d", &a[i]); 

        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            if (vis[a[i]])
                b[i] = a[vis[a[i]]];
            else
                b[i] = a[i];
            for (int j = 1; j <= (int)sqrt((double)a[i]) + 1; j++) {
                if (a[i] % j == 0) {
                    vis[j] = i;
                    vis[a[i] / j] = i;
                }
            }
        }

        memset(vis, 0, sizeof(vis));
        for (int i = n; i >= 1; i--) {
            if (vis[a[i]])
                c[i] = a[vis[a[i]]];
            else
                c[i] = a[i];
            for (int j = 1; j <= (int)sqrt((double)a[i]) + 1; j++) {
                if (a[i] % j == 0) {
                    vis[j] = i;
                    vis[a[i] / j] = i;
                }
            }
        }


        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += (ll)b[i] * c[i]; 
        }
        printf("%I64d\n", sum); 
    }
    return 0;
}
