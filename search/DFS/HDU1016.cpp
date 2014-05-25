#include <iostream>
#include <cstdio>
#include <cstring>
#define N 25

int n, arr[N], vis[N], isp[N * 10];

int is_prime(int x) {
    for (int i = 2; i <= x / 2; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

void init() {
    for (int i = 2; i <= n * 2; i++)
        isp[i] = is_prime(i);
}

void solve(int cur) {
    if (cur == n && isp[arr[0] + arr[n - 1]]) {
        for (int i = 0; i < n - 1; i++) 
            printf("%d ", arr[i]);
        printf("%d\n", arr[n - 1]); 
    }
    else for (int i = 2; i <= n; i++) 
        if (!vis[i] && isp[i + arr[cur - 1]]) {
            arr[cur] = i;
            vis[i] = 1; 
            solve(cur + 1); 
            vis[i] = 0;
        }
}

int main() {
    int t = 1;
    while (scanf("%d", &n) != EOF) {
        init();
        printf("Case %d:\n", t++);
        vis[1] = 1;
        arr[0] = 1;
        solve(1); 
        printf("\n");
    }
    return 0;
}
