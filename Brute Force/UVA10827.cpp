#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 205;

int arr[MAXN][MAXN], sum[MAXN];
int n, Max;

int deal() {
    int temp;
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {
            memset(sum, 0, sizeof(sum)); 
            for (int k = i; k < i + n; k++) {
                temp = 0;     
                for (int l = j; l < j + n; l++) {
                    sum[l] += arr[k][l]; 
                    temp += sum[l];
                    if (Max < temp)
                        Max = temp;
                } 
            } 
        }
    }
    return Max;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n); 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {  
                scanf("%d", &arr[i][j]);
                arr[i][j + n] = arr[i + n][j] = arr[i + n][j + n] = arr[i][j];
            }
        }
        Max = -INF;
        int ans = deal(); 
        printf("%d\n", ans);
    }
    return 0;
}
