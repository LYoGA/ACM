#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using std::make_pair;
using namespace std;

const int N = 400005;
const int INF = 1 << 30;
typedef pair<int, int> pii;

int n, m, s, t;
int d[N], rec[N];
int first[N], u[N], next[N], v[N], w[N];

struct cmp{
    bool operator() (const int a, const int b){
        return a % 10 > b % 10;  
    }
};

priority_queue<int, vector<pii>, greater<pii> > q;

void init() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < n; i++) 
        first[i] = -1;

    m *= 2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]); 
        next[i] = first[u[i]];
        first[u[i]] = i; 

        i++;
        v[i] = u[i - 1] , u[i] = v[i - 1], w[i] = w[i - 1];
        next[i] = first[u[i]];
        first[u[i]] = i; 
    }
}

void dijkstra() {
    bool done[N];
    for (int i = 0; i < n; i++) 
        d[i] = (i == s ? 0 : INF);
    memset(done, 0, sizeof(done));
    q.push(make_pair(d[s], s));
    while (!q.empty()) {
        pii u = q.top();
        q.pop();
        int x = u.second; 
        if (done[x]) 
            continue;
        done[x] = true;
        for (int i = first[x]; i != -1; i = next[i]) {
            if (d[v[i]] > d[x] + w[i]) {
                d[v[i]] = d[x] + w[i]; 
                q.push(make_pair(d[v[i]], v[i])); 
             }
        }
    }
}

int main() {
    int cas, o = 0;
    scanf("%d", &cas);
    while (cas--) {
        init(); 
        dijkstra(); 
        printf("Case #%d: ", ++o); 
        if (d[t] == INF)
            printf("unreachable\n");
        else
            printf("%d\n", d[t]);
    }
    return 0;
}
