#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 105;

int n, m, ans;
int arr[MAXN][MAXN], map[MAXN][MAXN], dp[MAXN];

bool judge(int *a, int *b) {
    for (int i = 0; i < m; i++)
        if (a[i] >= b[i])
            return false;
    return true;
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            scanf("%d", &arr[i][j]); 
        sort(arr[i], arr[i] + m);
    }
    memset(map, 0, sizeof(map));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (judge(arr[i], arr[j]))  
                map[i][j] = 1; 
}

int DP(int i) {
    if (dp[i] > 0)
        return dp[i];
    dp[i] = 1;
    for (int j = 0; j < n; j++)
        if (map[i][j])
            dp[i] = max(dp[i], DP(j) + 1);
    return dp[i];
}

void output(int i) {
    for (int j = 0; j < n; j++) {
        if (map[i][j] && dp[i] == dp[j] + 1) {
            printf(" %d", j + 1); 
            output(j); 
            break;
        }      
    } 
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        init(); 
        memset(dp, 0, sizeof(dp));
        int ans = -1, pos;
        for (int i = 0; i < n; i++) {
            int num = DP(i);
            if (ans < num) {
                ans = num; 
                pos = i;
            }
        }
        printf("%d\n", ans);
        printf("%d", pos + 1);       
        output(pos);
        printf("\n");
    } 
    return 0;
}
