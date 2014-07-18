#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>

using namespace std;

const int MAXN = 10005;
const int INF = 0x3f3f3f3f;


char str[MAXN];
int d[MAXN][MAXN];

int dp(int a, int b) {
    if (a >= b)
        return 0;
    if (d[a][b] != INF)
        return d[a][b];
    if (str[a] == str[b])
        d[a][b] = dp(a + 1, b - 1);
    d[a][b] = min(d[a][b], min(dp(a + 1, b), dp(a, b - 1)) + 1);;
}

void outPut(int a, int b) {
    if (a > b)
        return;
    if (a == b) {
        printf("%c", str[a]); 
        return; 
    }
    if (str[a] == str[b]) {
        printf("%c", str[a]); 
        outPut(a + 1, b - 1); 
        printf("%c", str[a]);
    }
    else if (d[a][b] == d[a + 1][b] + 1) {
        printf("%c", str[a]); 
        outPut(a + 1, b);
        printf("%c", str[a]); 
    }
    else {
        printf("%c", str[b]); 
        outPut(a, b - 1);
        printf("%c", str[b]);  
    }
}

int main() {
    while (scanf("%s", str) != EOF) {
        int l = strlen(str); 
        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++)
                d[i][j] = INF;
        int ans = dp(0, l - 1);
        printf("%d ", ans); 
        outPut(0, l - 1);
        printf("\n");
    }
    return 0;
}
