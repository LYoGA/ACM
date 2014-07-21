#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 105;

int arr[MAXN], d[MAXN][MAXN], sum[MAXN][MAXN];
int n; 

void init() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = -INF;

    for (int i = 0; i < n; i++) { 
        int num = 0;
        for (int j = i; j < n; j++) { 
            num += arr[j];
            sum[i][j] = num;
        } 
    }
}

int dp(int a, int b) {
    int &ans = d[a][b];
    if (a > b)
        return 0;
    if (ans != -INF)
        return ans;
    for (int k = 1; k <= b - a + 1; k++) 
        ans = max(ans, sum[a][b] - min(dp(a, b - k), dp(a + k, b))); 
    return ans;
}

int main() {     
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]); 
        init();
        int ans = dp(0, n - 1); 
        printf("%d\n", 2 * ans - sum[0][n - 1]);  
    }           
    return 0;
}

