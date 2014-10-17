#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 50005;

struct edge{
    edge() {}
    edge(int uu, int vv) {
        u = uu; 
        v = vv;
    }
    int u, v;
};

vector<int> g[MAXN], bcc[MAXN];
stack<edge> s;
int pre[MAXN], iscut[MAXN], bccno[MAXN];
int n, dfs_clock, bcc_cnt, tmp;

int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        edge e(u, v); 
        if (!pre[v]) {
            s.push(e);
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u]) {
                iscut[u] = true; 
                bcc_cnt++; 
                bcc[bcc_cnt].clear();
                for (;;) {
                    edge x = s.top(); 
                    s.pop(); 
                    if (bccno[x.u] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u] = bcc_cnt;
                    }
                    if (bccno[x.v] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v] = bcc_cnt;
                    }
                    if (x.u == u && x.v == v) break;
                }
            }
        }
        else if (pre[v] < pre[u] && v != fa) {
            s.push(e); 
            lowu = min(lowu, pre[v]);
        }
    }
    if (fa < 0 && child == 1) iscut[u] = 0;
    return lowu;
}

void find_bcc(int n) {
    memset(pre, 0, sizeof(pre));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    dfs_clock = bcc_cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!pre[i])
            dfs(i, -1);
}

int main() {
    int t = 1;
    while (scanf("%d", &n) && n) {
        int u, v; 
        for (int i = 0; i < MAXN; i++)
            g[i].clear();
        tmp = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
            tmp = max(max(tmp, u), v);
        } 
        find_bcc(tmp);

        ll ans1 = 0, ans2 = 1;
        if (bcc_cnt == 1) {
            ans1 = 2; 
            ans2 = bcc[1].size() * (bcc[1].size() - 1) / 2;
        }
        else {
            for (int i = 1; i <= bcc_cnt; i++) {
                int cnt_cnt = 0; 
                for (int j = 0; j < bcc[i].size(); j++) 
                    if (iscut[bcc[i][j]])
                        cnt_cnt++;
                if (cnt_cnt == 1) {
                    ans1++; 
                    ans2 *= (ll)(bcc[i].size() - cnt_cnt);
                }
            } 
        }
        printf("Case %d: %lld %lld\n", t++, ans1, ans2);
    } 
    return 0;
}
