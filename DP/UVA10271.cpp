#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 5005;
const int INF = 0x3f3f3f3f;

int arr[MAXN];
int K, n;
ll d[MAXN][MAXN];

void init() {
    for (int i = 0; i <= n; i++) {
        d[i][0] = 0;
        for (int j = 1; j <= K; j++) 
            d[i][j] = INF;
    }
}

void dp() {
    for (int i = 3; i <= n; i++)
        for (int j = 1; j <= K; j++) 
            if (i >= j * 3) 
                d[i][j] = min(d[i - 2][j - 1] + (arr[i] - arr[i - 1]) * (arr[i] - arr[i - 1]), d[i - 1][j]);  
}

int main() {
    int cas;    
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d %d", &K, &n); 
        K += 8;
        for (int i = n; i >= 1; i--)
            scanf("%d", &arr[i]);
        init();
        dp();
        printf("%lld\n", d[n][K]); 
    }
    return 0;
}
