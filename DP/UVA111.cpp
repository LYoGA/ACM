#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 105;

int n;
int d[MAXN][MAXN], arr1[MAXN], arr2[MAXN];

int dp(){
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            if (arr1[i - 1] == arr2[j - 1]) 
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]); 
        }
    return d[n][n];
}

int main(){
    int temp; 
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp); 
        arr1[temp - 1] = i;
    }
    while (scanf("%d", &temp) != EOF) {
        arr2[temp - 1] = 1; 
        memset(d, 0, sizeof(d));
        for (int i = 2; i <= n; i++) {
            scanf("%d", &temp); 
            arr2[temp - 1] = i; 
        } 
        int ans = dp(); 
        printf("%d\n", ans);
    } 
    return 0;
}
