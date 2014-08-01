#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

long long arr[MAXN], c[MAXN], tot, M;

int main() {
    int n;    
    while (scanf("%d", &n) == 1) {
        tot = 0; 
        for (int i = 1; i <= n ;i++) {
            scanf("%lld", &arr[i]); 
            tot += arr[i]; 
        }
        M = tot / n;
        c[0] = 0;  
        for (int i = 1; i < n; i++)
            c[i] = c[i - 1] + arr[i] - M;
        sort(c, c + n); 
        long long x1 = c[n / 2], ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(x1 - c[i]);
        printf("%lld\n", ans); 
    }
    return 0;
}
