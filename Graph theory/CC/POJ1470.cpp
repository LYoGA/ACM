#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
const int MAXM = 501010;

int f[MAXN];
int n;

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) f[pa] = pb;
}

bool vis[MAXN];
int ancestor[MAXN];
struct Edge{
    int to, next;
}edge[MAXN * 2];
int head[MAXN], tot;

void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

struct Query{
    int q, next;
    int index;
}query[MAXM * 2];
int ans[MAXM], h[MAXM];
bool flag[MAXN];
int cnt[MAXN];
int tt, Q;

void add_query(int u, int v, int index) {
    query[tt].q = v;
    query[tt].next = h[u];
    query[tt].index = index;
    h[u] = tt++;
}

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
    tt = 0;
    memset(h, -1, sizeof(h));
    memset(f, -1, sizeof(f));
    memset(vis, false, sizeof(vis));
    memset(ancestor, 0, sizeof(ancestor));
    for (int i = 1; i <= n; i++)
        f[i] = i;
}

void LCA(int u) {
    ancestor[u] = u;
    vis[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to; 
        if (vis[v]) continue;
        LCA(v);
        Union(u, v);
        ancestor[find(u)] = u; 
    }
    for (int i = h[u]; i != -1; i = query[i].next) {
        int v = query[i].q; 
        if (vis[v]) {
            ans[query[i].index] = ancestor[find(v)]; 
        }
    }
}

int main() {
    int u, v, k;
    while (scanf("%d", &n) == 1) {
        init();
        memset(flag, false, sizeof(flag));         
        for (int i = 1; i <= n; i++) {
            scanf("%d: (%d)", &u, &k); 
            while (k--) {
                scanf("%d", &v);
                flag[v] = true; 
                addedge(u, v);
                addedge(v, u);
            }
        }
        scanf("%d", &Q); 
        for (int i = 0; i < Q; i++) {
            char ch; 
            cin >> ch;
            scanf("%d %d)", &u, &v);
            add_query(u, v, i); 
            add_query(v, u, i); 
        }
        int root; 
        for (int i = 1; i <= n; i++) {
            if (!flag[i]) {
                root = i; 
                break;
            }
        }
        LCA(root);

        memset(cnt, 0,  sizeof(cnt));  
        for (int i = 0; i < Q; i++)
            cnt[ans[i]]++;
        for (int i = 1; i <= n; i++)
            if (cnt[i] > 0)
                printf("%d:%d\n", i, cnt[i]);
    }
    return 0;
}

