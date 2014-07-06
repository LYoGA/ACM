#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000005;

int n, m; 
int dp[MAXN], arr[MAXN];

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < m; i++)
            scanf("%d", &arr[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < m; j++) {
                if (i >= arr[j] && dp[i - arr[j]] == 0) {          
                    dp[i] = 1;  
                    break; 
                }
            } 
        if (dp[n])
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
