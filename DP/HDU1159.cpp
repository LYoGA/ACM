#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1005;

char s1[N], s2[N];
int dp[N][N];

int LCSL(int l1, int l2) {
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    } 
    return dp[l1][l2];
}

int main () {
    while (scanf("%s", s1) != EOF) {
        scanf("%s", s2);
        memset(dp, 0, sizeof(dp));
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        printf("%d\n", LCSL(len1, len2));
    }
    return 0;
}
