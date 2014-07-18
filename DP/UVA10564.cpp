#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100;

int n, s;
int arr[MAXN][MAXN];
long long d[MAXN][MAXN][505];

void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
            scanf("%d", &arr[i][j]);

    for (int i = n + 1; i <= n * 2 - 1; i++)
        for (int j = 1; j <= i - n + 1; j++)
            scanf("%d", &arr[i][j]);
}

long long dp() {
    for (int i = 1; i <= n; i++)
        d[n * 2 - 1][i][arr[n * 2 - 1][i]] = 1;
    
    for (int i = n * 2 - 2; i >= n; i--)
        for (int j = 1; j <= i - n + 1; j++) 
            for (int k = arr[i][j]; k <= s; k++) {
                int temp = arr[i][j]; 
                d[i][j][k] = d[i + 1][j][k - temp] + d[i + 1][j + 1][k - temp]; 
            } 

    long long num = 0;
    for (int i = n - 1; i >= 1; i--) 
        for (int j = 1; j <= n - i + 1; j++) {
            for (int k = arr[i][j]; k <= s; k++) {
                int temp = arr[i][j]; 
                if (j == 1)        
                    d[i][j][k] += d[i + 1][j][k - temp];
                else if (j == n - i + 1)
                    d[i][j][k] += d[i + 1][j - 1][k - temp];
                else
                    d[i][j][k] = d[i + 1][j][k - temp] + d[i + 1][j - 1][k - temp];  
            }
            if (i == 1)
                num += d[i][j][s];
        }
    return num;        
}

void outPut(int x, int y, int sum) {
    if (x >= n * 2 - 1)
        return;
    int temp = arr[x][y]; 
    if (x < n) {
        if (y > 1 && d[x + 1][y - 1][sum - temp]) {
            printf("L"); 
            outPut(x + 1, y - 1, sum - temp);
            return;
        } 
        else {
            printf("R"); 
            outPut(x + 1, y, sum - temp);  
            return;
        }
    }
    else {
        if (d[x + 1][y][sum - temp]) {
            printf("L"); 
            outPut(x + 1, y, sum - temp);
            return; 
        } 
        else {
            printf("R"); 
            outPut(x + 1, y + 1, sum - temp);  
            return;
        }
    }
}

int main() {
    while (scanf("%d %d", &n, &s) && n || s) {
        init();     
        memset(d, 0, sizeof(d));
        long long ans = dp();
        cout << ans << endl;
        for (int i = 1; i <= n; i++) 
            if (d[1][i][s]) {
                printf("%d ", i - 1); 
                outPut(1, i, s); 
                break;
            }
        printf("\n");
    }
    return 0;
}

