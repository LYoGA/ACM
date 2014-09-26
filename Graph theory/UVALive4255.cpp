#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 30;

char str[MAXN * 10];
int in[MAXN], vis[MAXN], g[MAXN][MAXN], sum[MAXN];
int n;

void toposort() {
    int d = 0, low = -10;
    while (d <= n) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i <= n; i++) {
            if (in[i] == 0) {
                sum[i] = low; 
                in[i] = -1;
                vis[i] = 1;
                d++;
            }
        }
        low++;
        for (int i = 0; i <= n; i++) {
            if (vis[i]) {
                for (int j = 0; j <= n; j++) 
                    if (g[i][j])
                        in[j]--; 
            }
        }
    } 
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);       
        scanf("%s", str);
        memset(in, 0, sizeof(in));
        memset(g, 0, sizeof(g));
        memset(sum, 0, sizeof(sum));
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (str[cnt] == '+') {
                    in[j]++;
                    g[i - 1][j] = 1; 
                } 
                else if (str[cnt] == '-') {
                    in[i - 1]++;  
                    g[j][i - 1] = 1;
                }
                cnt++;
            }
        }         
        toposort();
        for (int i = 1; i <= n; i++) {
            if (i == 1)
                printf("%d", sum[i] - sum[i - 1]);
            else 
                printf(" %d", sum[i] - sum[i - 1]); 
        }
        printf("\n");
    }
    return 0;
}
