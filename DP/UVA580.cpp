#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 55;

int dp[MAXN];
int n;

void init(){
    memset(dp, 0, sizeof(dp));
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;
    for (int i = 4; i < MAXN; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
}

int main() {
    init();
    while (scanf("%d", &n) && n) {
        int ans = pow(2, n);
        ans -= dp[n];
        printf("%d\n", ans);  
    } 
    return 0;
}
