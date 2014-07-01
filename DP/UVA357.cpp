//二维dp
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 30005;

long long d[MAXN][5];
int n;
int coin[] = {1, 5, 10, 25, 50};

long long dp(int s, int m) {
    if (d[s][m] != -1)
        return d[s][m];
    d[s][m] = 0;
    for (int i = m; i <= 4 && s >= coin[i]; i++)
        d[s][m] += dp(s - coin[i], i);
    return d[s][m];
}

int main() {
    memset(d, -1, sizeof(d)); 
    for (int i = 0; i <= 4; i++)
        d[0][i] = 1;
    while (scanf("%d", &n) != EOF) {
        long long ans = dp(n, 0); 
        if (ans > 1) 
            printf("There are %lld ways to produce %d cents change.\n", ans, n);
        else
            printf("There is only 1 way to produce %d cents change.\n", n);
    }
    return 0;
}



//一维dp
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 30005;

long long dp[MAXN];
int coin[] = {1, 5, 10, 25, 50};
int n;

void init() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; 
    for (int i = 0; i < 5; i++)
        for (int j = coin[i]; j < MAXN; j++)
            dp[j] += dp[j - coin[i]]; 
}

int main() {
    init();
    while (scanf("%d", &n) != EOF) {
        long long ans = dp[n]; 
        if (ans == 1)          
            printf("There is only 1 way to produce %d cents change.\n", n);  
        else 
            printf("There are %lld ways to produce %d cents change.\n", ans, n);  
    }
    return 0;
}
