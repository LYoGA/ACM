#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 32000;
const int N = 105;

int arr[N], vis[N][MAXN * 2 + 5];
int n, m, flag;
char path[N];

bool judge(int cur, int sum) {
    return abs(sum) <= MAXN && !vis[cur][sum + MAXN]; 
}

void dfs(int cur, int sum) {
    if (flag)
        return;
    if (cur == n) { 
        if (sum == m) 
            flag = 1; 
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (i == 0 && judge(cur, sum + arr[cur])) {
            vis[cur][sum + arr[cur] + MAXN] = 1; 
            path[cur] = '+';
            dfs(cur + 1, sum + arr[cur]);
        }         
        if (i == 1 && judge(cur, sum - arr[cur])) {
            vis[cur][sum - arr[cur] + MAXN] = 1; 
            path[cur] = '-';
            dfs(cur + 1, sum - arr[cur]);
        } 
        if (i == 2 && judge(cur, sum * arr[cur])) {
            vis[cur][sum * arr[cur] + MAXN] = 1; 
            path[cur] = '*';
            dfs(cur + 1, sum * arr[cur]); 
        }
        if (i == 3 && arr[cur] != 0 && judge(cur, sum / arr[cur])) {
            vis[cur][sum / arr[cur] + MAXN] = 1; 
            path[cur] = '/';
            dfs(cur + 1, sum / arr[cur]); 
        } 
        if (flag)
            return;
    } 
}

void outPut() {
    for (int i = 0; i < n; i++) {
        if (i) 
            printf("%c%d", path[i], arr[i]);
        else
            printf("%d", arr[i]);
    }
    printf("=%d\n", m);
}

int main() {
    int cas;    
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);    
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &m); 

        memset(vis, 0, sizeof(vis));
        vis[0][arr[0] + MAXN] = 1;
        flag = 0;
        dfs(1, arr[0]); 

        if (flag) 
            outPut(); 
        else 
            printf("NO EXPRESSION\n");
    }
    return 0;
}
