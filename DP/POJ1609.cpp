#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct block{
    int l, m;
}b[MAXN];

int dp[MAXN];

int cmp(const block a, const block b) {
    if (a.l != b.l)
        return a.l < b.l;
    else
        return a.m < b.m;
}

int main() {
    int n;    
    while (scanf("%d", &n)) {
        if (n == 0) {
            printf("*\n"); 
            break;
        }
        for (int i = 0; i < n; i++) 
            scanf("%d %d", &b[i].l, &b[i].m); 
        sort(b, b + n, cmp);
        memset(dp, 0, sizeof(dp));
        int Max = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;  
            for (int j = 0; j < i; j++) 
                if (b[i].l >= b[j].l && b[i].m >= b[j].m) 
                    dp[i] = max(dp[i], dp[j] + 1);
            if (dp[i] > Max)
                Max = dp[i];
        }
        printf("%d\n", Max);
    }
    return 0;
}
