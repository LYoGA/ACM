#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1005;

struct elephant{
    int w, s, p;
}e[MAXN];

int dp[MAXN], vis[MAXN];
int n, m, cnt;

bool cmp(const elephant& a, const elephant& b) {
    return a.w < b.w;
}

int DP(int i) {
    if (dp[i] > 0)
        return dp[i];
    dp[i] = 1; 
    for (int j = i + 1; j < cnt; j++) {
        if (e[i].w < e[j].w && e[i].s > e[j].s) 
            dp[i] = max(dp[i], DP(j) + 1); 
    }
    return dp[i]; 
}

void output(int i) {
    printf("%d\n", e[i].p + 1);
    for (int j = 0; j < cnt; j++) {
        if (e[i].w < e[j].w && e[i].s > e[j].s && dp[i] == dp[j] + 1) {
            output(j); 
            break;
        }
    }
}

int main() {
    cnt = 0;
    while (scanf("%d %d", &n, &m) != EOF) {
        e[cnt].w = n; 
        e[cnt].s = m; 
        e[cnt].p = cnt;
        cnt++;
    }
    sort(e, e + cnt, cmp);
    memset(dp, 0, sizeof(dp));  
    memset(vis, 0, sizeof(vis));
    int ans = -1, maxi; 
    for (int i = 0; i < cnt; i++) {
        int max = DP(i);     
        if (max > ans) {
            ans = max; 
            maxi = i; 
        } 
    }
    printf("%d\n", ans);
    output(maxi);
    return 0;
}
