#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 50005;

int dp[MAXN], coin[MAXN];
int n, m;

int main() {
    scanf("%d", &n);
    while (n--) {
        int sum = 0;
        scanf("%d", &m); 
        for (int i = 0; i < m; i++) {
            scanf("%d", &coin[i]);
            sum += coin[i]; 
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = sum; j >= coin[i]; j--) {
                if (dp[j - coin[i]])  
                    dp[j] = 1;  
            }  
        } 
        for (int i = sum / 2; i >= 0; i--) 
            if (dp[i]) {
                printf("%d\n", sum - 2 * i); 
                break;
            }
    }
    return 0;
}
