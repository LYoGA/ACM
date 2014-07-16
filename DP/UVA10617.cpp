#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 65;

char str[MAXN];
long long d[MAXN][MAXN];

long long dp(int a, int b) {
    if (a > b)
        return 0;
    if (a == b)
        return d[a][b] = 1;
    if (d[a][b] != -1)
        return d[a][b];
    if (str[a] == str[b])
        d[a][b] = dp(a + 1, b) + dp(a, b - 1) + 1; 
    else
        d[a][b] = dp(a + 1, b) + dp(a, b - 1) - dp(a + 1, b - 1);
    return d[a][b];
}
int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", str);    
        int l = strlen(str);
        memset(d, -1,sizeof(d));
        printf("%lld\n", dp(0, l - 1));
    }
    return 0;
}

/*
for (int i = 0; i < l; i++) 
    d[i][i] = 1;
for (int i = l - 1; i >= 0; i--)
    for (int j = i + 1; j < l; j++)
        if (str[i] == str[j])
            d[i][j] = d[i + 1][j] + d[i][j - 1] + 1;
        else 
            d[i][j] = d[i + 1][j] + d[i][j - 1] - d[i + 1][j - 1]; 
*/
