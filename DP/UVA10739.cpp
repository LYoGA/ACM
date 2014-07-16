#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

char str[MAXN];
int d[MAXN][MAXN];

int dp(int a, int b) {
    if (a >= b)
        return 0;
    if (d[a][b] != -1)
        return d[a][b];
    if (str[a] == str[b]) 
        d[a][b] = dp(a + 1, b - 1); 
    else 
        d[a][b] = min(min(dp(a + 1, b), dp(a, b - 1)), dp(a + 1, b - 1)) + 1; 
    return d[a][b];
}

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", str); 
        int len = strlen(str);
        memset(d, -1, sizeof(d));
        int ans = dp(0, len - 1);
        printf("Case %d: %d\n", t++, ans); 
    }
    return 0;
} 
