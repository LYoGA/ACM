#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 55;

int arr[MAXN][MAXN], num[MAXN], Max[MAXN], sum[MAXN][MAXN];
int w, b, ans;

int main() {
    while (scanf("%d", &w) && w) {
        ans = 0;
        memset(Max, 0, sizeof(Max));
        memset(sum, 0, sizeof(sum));
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= w; i++) {
            scanf("%d", &b);
            num[i] = b;
            Max[i] = -INF;
            for (int j = 1; j <= b; j++) { 
                scanf("%d", &arr[i][j]);
                arr[i][j] = 10 - arr[i][j];
                sum[i][j] = sum[i][j - 1] + arr[i][j];
                if (sum[i][j] > Max[i]) 
                    Max[i] = sum[i][j];
            } 
            ans += Max[i];
        } 



      /*  for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= num[i]; j++) 
                printf("%d ", sum[i][j]);
            printf("\n");
        }
        for (int i = 1; i <= w; i++) {
            printf("%d\n", Max[i]);
        }*/
        printf("Workyards %d\n", w);
        printf("Maximum profit is %d.\n", ans);
    //  printf("Number of pruls to buy:");
    }
    return 0;
}
