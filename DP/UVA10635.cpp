#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 250 * 250;
const int INF = 0x3f3f3f3f;

int S[MAXN], g[MAXN], d[MAXN];
int num[MAXN];
int n, p, q, x, cnt; 

int dp() {
    for (int i = 1; i <= cnt; i++)
        g[i] = INF;
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        int k = lower_bound(g + 1, g + cnt + 1, S[i]) - g; 
        d[i] = k; 
        g[k] = S[i]; 
        ans = max(ans, d[i]);
    }
    return ans;
}

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &n, &p, &q); 
        memset(num, 0,sizeof(num));
        for (int i = 1; i <= p + 1; i++) {
            scanf("%d", &x); 
            num[x] = i; 
        }
        cnt = 0;
        for (int i = 1; i <= q + 1; i++) {
            scanf("%d", &x); 
            if (num[x]) 
                S[cnt++] = num[x];
        }

        printf("Case %d: %d\n", t++, dp()); 
    }
    return 0;
}
