#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int arr[MAXN], dp[MAXN];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) 
            if (arr[i] > arr[j])       
                dp[i] = max(dp[i], dp[j] + 1);
        if (dp[i] > ans)
            ans = dp[i];
    }
    printf("%d\n", ans);
    return 0;
}
