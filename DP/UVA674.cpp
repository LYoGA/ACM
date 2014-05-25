#include <iostream>
#include <cstdio>
#include <cstring>
#define N 7490 

using namespace std;

int d[N][6], n;
int coin[] = {0, 1, 5, 10, 25, 50};

int dp(int s, int m) {
    if (d[s][m] != -1) return d[s][m];
    d[s][m] = 0; 
    for (int i = m; i <= 5 && s >= coin[i]; i++)
        d[s][m] += dp(s - coin[i], i);
    return d[s][m];
}

int main () {
    memset(d, -1, sizeof(d));
    for (int i = 0; i <= 5; i++)  d[0][i] = 1;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", dp(n, 1)); 
    }
    return 0;
}
