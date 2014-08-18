#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 5;
const int N = 5;

int sum[MAXN], arr[10005][N];
int n, k, ans;

void build() {
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < MAXN; j++) {
            int temp = 0; 
            for (int k = 0; k < N; k++)
                if (j & (1 << k))
                    temp += arr[i][k];
            sum[j] = max(sum[j], temp); 
        } 
}

void dfs(int S, int cnt, int x) {
    if (cnt == k) {
        ans = max(ans, x); 
    }
    for (int i = S; i; i = (i - 1) & S)
        dfs(S ^ i, cnt + 1, x + sum[i]);
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < N; j++) 
                scanf("%d", &arr[i][j]); 
        
        ans = 0;
        if (k >= 5) {
            for (int i = 0; i < N; i++) {
                int temp = 0;
                for (int j = 0; j < n; j++)  
                    temp = max(temp, arr[j][i]);
                ans += temp;     
            } 
        }
        else {
            build(); 
            dfs(MAXN - 1, 0, 0); 
        }
        printf("%d\n", ans); 
    }
    return 0;
}

