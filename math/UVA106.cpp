#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 1000005;
long long n;
int vis[N];

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    while (scanf("%lld", &n) != EOF) {
        int ans1 = 0, ans2 = 0;
        memset(vis, 0, sizeof(vis));
        long long m = sqrt(n + 0.5);
        long long a, b, c;
        for (long long i = 1; i <= m; i++) {
            for (long long j = i + 1; j <= m; j += 2) {
                if (gcd(j, i) == 1) {      
                    a = j * j - i * i; 
                    b = 2 * i * j; 
                    c = i * i + j * j; 
                    if (c <= n) {
                        ans1++; 
                        vis[a] = vis[b] = vis[c] = 1; 
                    }
                    for (int k = 2; c * k <= n; k++)
                        vis [k * a] = vis[k * b] = vis[k * c] = 1;
                } 
            }
        }
        for (int i = 1; i <= n; i++)
            if (vis[i])
                ans2++;
        printf("%d %d\n", ans1++, n - ans2++);
    }
    return 0;
}
