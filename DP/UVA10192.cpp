#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int d[MAXN][MAXN];
char s1[MAXN], s2[MAXN];

int dp(int l1, int l2) {
    for (int i = 1; i <= l1; i++)
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) 
                d[i][j] = d[i - 1][j - 1] + 1;
            else  
                d[i][j] = max(d[i - 1][j], d[i][j - 1]); 
        }
    return d[l1][l2];
}

int main() {
    int t = 1;
    while (gets(s1) != NULL) {
        if (strcmp(s1, "#") == 0)
            break;
        gets(s2);
        memset(d, 0, sizeof(d));
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int ans = dp(len1, len2);
        printf("Case #%d: you can visit at most %d cities.\n", t++, ans);
    }
    return 0;
}
