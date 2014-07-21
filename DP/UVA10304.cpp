#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


const int MAXN = 255;
const int INF = 0x3f3f3f3f;
int arr[MAXN], sum[MAXN], d[MAXN][MAXN];
int n;

int main() {
    while(scanf("%d", &n) != EOF) {
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            sum[i] = sum[i - 1] + arr[i]; 
        }
        memset(d, 0, sizeof(d));
        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                d[j][i] = INF; 
                for (int k = j; k <= i; k++)
                    d[j][i] = min(d[j][i], d[j][k - 1] + d[k + 1][i] + sum[i] - sum[j - 1] - arr[k]); 
            }  
        }
        printf("%d\n", d[1][n]);

    }
    return 0;
}
