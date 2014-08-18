#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 9876543210;

ll ans, n;
int vis[100];


int judge(ll x) {
    memset(vis, 0, sizeof(vis));
    while (x) {
        int temp = x % 10;
        if (vis[temp])
            return false;
        vis[temp] = 1;  
        x /= 10; 
    }
    return true;
}

int main() {
    int cas;
    scanf("%d", &cas);
    for (int i = 0; i < cas; i++) {
        if (i) 
            printf("\n");
        scanf("%lld", &n);
        for (ll i = 1; i <= MAXN; i++) {
            ans = i * n;
            if (ans > MAXN)
                break;
            if (judge(ans) && judge(i))
                printf("%lld / %lld = %lld\n", ans, i, n);
        }
    }
    return 0;
}
