#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 105;

int arr[MAXN][MAXN], sum[MAXN][MAXN], s[MAXN][MAXN];

int main() {
    int n;    
    while (scanf("%d", &n) != EOF) {
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) {
                scanf("%d", &arr[i][j]);  
                s[i][j] = s[i][j - 1] + arr[i][j];
            }

        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) 
                sum[i][j] = sum[i - 1][j] + s[i][j];
        } 

        int Max = -INF;
        for (int i = 1; i <= n; i++) {  
            for (int j = 0; j < i; j++) {  
                int t, Min;  
                Min = 0;  
                for (int k = 1; k <= n; k++) {  
                    t = sum[i][k] - sum[j][k] - Min;  
                    if (t > Max) 
                        Max = t;  
                    if (sum[i][k] - sum[j][k] < Min)  
                        Min = sum[i][k] - sum[j][k];  
                }  
            }  
        }  
        printf("%d\n", Max);
    }
    return 0;
}
