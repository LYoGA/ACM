#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

int a[MAXN], dp[MAXN];

int main() {
    int n, t = 0;
    while (scanf("%d", &n) && n != -1) {
        a[0] = n; 
        int cnt = 1;
        while (scanf("%d", &a[cnt]) && a[cnt] != -1) 
            cnt++; 
        memset(dp, 0, sizeof(dp)); 
        int Max = 0;
        for (int i = 0; i < cnt; i++) {
            dp[i] = 1; 
            for (int j = 0; j < i; j++) {
                if (a[i] <= a[j]) 
                    dp[i] = max(dp[i], dp[j] + 1); 
            } 
            if (dp[i] > Max)
                Max = dp[i];
        }
        if (t)
            printf("\n");
        printf("Test #%d:\n", ++t);
        printf("  maximum possible interceptions: %d\n", Max);
    } 
    return 0;
}
