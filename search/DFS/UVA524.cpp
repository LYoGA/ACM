#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int n;
int arr[MAXN], prime[MAXN], vis[MAXN];

int is_prime(int x) {
    if (x == 2) return 1;
    for (int i = 2; i < MAXN; i++)  
        if (x != i && x % i == 0)
            return 0;
    return 1;
}

void init() {
    for (int i = 2; i < MAXN; i++)
        prime[i] = is_prime(i);
}

void dfs(int cur) {
    if (cur == n && prime[arr[0] + arr[n - 1]]) {
        printf("%d", arr[0]);
        for (int i = 1; i < n; i++) 
            printf(" %d", arr[i]);
        printf("\n");
    }
    else {
        for (int i = 2; i <= n; i++) 
            if (!vis[i] && prime[i + arr[cur - 1]]) {
                arr[cur] = i; 
                vis[i] = 1;
                dfs(cur + 1);
                vis[i] = 0; 
            } 
    }
}

int main() {
    int t = 0;    
    init(); 
    while (scanf("%d", &n) != EOF) {
        arr[0] = 1;
        memset(vis, 0, sizeof(vis));
        if (t)
            printf("\n");
        printf("Case %d:\n", ++t);
        dfs(1);
    }
    return 0;
}
