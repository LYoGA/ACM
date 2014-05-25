#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1005;

int dp[MAXN], a[MAXN];

int main () {
    int n, Max;
    while (scanf("%d", &n) && n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) 
            scanf("%d", &a[i]); 
        Max = dp[0] = a[0];
        for (int i = 1; i < n; i++) {
            dp[i] = a[i];
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    if (dp[i] < dp[j] + a[i]) 
                        dp[i] = dp[j] + a[i];
                }         
            } 
            if (dp[i] > Max)
                Max = dp[i];
        } 
        printf("%d\n", Max);
    }
    return 0;
}
