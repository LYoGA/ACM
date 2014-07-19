#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10005;

int n, cnt;
int city[MAXN], price[MAXN], d[MAXN][205]; 
char str[MAXN];

void dp() {
    for (int i = 0; i < cnt; i++)  
        for (int j = 0; j <= 200; j++)
            d[i][j] = INF;

    d[0][100] = 0;
    for (int i = 1; i < cnt; i++) {
        int dis = city[i] - city[i - 1];

        for (int j = 0; j + dis <= 200; j++)
            if (d[i - 1][j + dis] != INF)
                d[i][j] = d[i - 1][j + dis];

        for (int j = 0; j <= 200; j++) 
            for (int k = 0; k <= j; k++) {
                if (j + dis - k <= 200 && d[i - 1][j + dis - k] != INF)
                    d[i][j] = min(d[i][j], d[i - 1][j + dis - k] + k * price[i]);
            }   
    }
}

int main() {
    int cas;
    scanf("%d", &cas);
    getchar();
    while (cas--) {
        memset(city, 0, sizeof(city));
        memset(price, 0, sizeof(price));
        scanf("%d%*c", &n); 
        cnt = 1;
        while (gets(str) != NULL && str[0] != '\0') {  
            sscanf(str, "%d %d", &city[cnt], &price[cnt]);  
            cnt++;  
        }  

        dp();
        if (100 < n - city[cnt - 1] || d[cnt - 1][100 + n - city[cnt - 1]] == INF)
            printf("Impossible\n");
        else
            printf("%d\n", d[cnt - 1][100 + n - city[cnt - 1]]);
        if (cas)
            printf("\n");
    }
    return 0;
}
