#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
const int N = 15;

int dp[MAXN], n;
char str[N];

int dfs(int cur) {
    if (dp[cur] != -1) 
        return dp[cur];
    dp[cur] = 0;
    for (int i = 0; i < 12; i++) {
        if (cur & (1 << i))  
            dp[cur]++; 
    }
    for (int i = 0; i < 10; i++) {
        int temp = cur; 
        if ((temp & (1 << i)) && (temp & (1 << (i + 1))) && !(temp & (1 << (i + 2)))) {
            temp ^= (1 << i); 
            temp ^= (1 << (i + 1)); 
            temp |= (1 << (i + 2)); 
            dp[cur] = min(dp[cur], dfs(temp));
        } 
        temp = cur;
        if (!(temp & (1 << i)) && (temp & (1 << (i + 1))) && (temp & (1 << (i + 2)))) {
            temp |= (1 << i); 
            temp ^= (1 << (i + 1)); 
            temp ^= (1 << (i + 2)); 
            dp[cur] = min(dp[cur], dfs(temp));
        } 
    }
    return dp[cur];
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str); 
        int len = strlen(str); 
        int start = 0; 
        for (int i = 0; i < len; i++) {
            if (str[i] == 'o') 
                start |= (1 << i); 
        }
        memset(dp, -1, sizeof(dp));
        int ans = dfs(start); 
        printf("%d\n", ans);
    }
    return 0;
}

