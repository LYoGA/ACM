#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 30005;

long long d[MAXN][11];
double n, num;
int coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long long int dp(int s, int m) {
    if (d[s][m] != -1)
        return d[s][m];
    d[s][m] = 0;
    for (int i = m; i <= 10 && s >= coin[i]; i++)
        d[s][m] += dp(s - coin[i], i);
    return d[s][m];
}

int main() {
    memset(d, -1, sizeof(d)); 
    for (int i = 0; i <= 10; i++)
        d[0][i] = 1;
    while (scanf("%lf", &n) && n) {
        num = (int)(n * 100 + 0.5);
        printf("%6.2lf%17lld\n", n, dp(num, 0));     
    }
    return 0;
}
