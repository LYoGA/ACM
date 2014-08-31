#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef __int64 ll;

const int MAXN = 100005;

ll sum[MAXN], stack[MAXN], hurt[MAXN];
int L[MAXN], R[MAXN], d[MAXN];
int n;

int main() {
    while (scanf("%d", &n) && n) {
        memset(stack, 0, sizeof(stack));
        memset(sum, 0, sizeof(sum));
        memset(hurt, 0, sizeof(hurt));
        int a;
        scanf("%d", &a);
        for (int i = 1; i <= a; i++) {
            scanf("%d%d%d", &L[i], &R[i], &d[i]);
            stack[L[i]] += d[i];
            stack[R[i] + 1] -= d[i];
        }

        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + stack[i];  
        }//每格的伤害
        for (int i = 1; i <= n; i++) {
            hurt[i] = hurt[i - 1] + sum[i]; 
        }//从第1格到第i格的伤害

        ll h; 
        int ans = 0, x, b;
        scanf("%d", &b);
        for (int i = 0; i < b; i++) {
            scanf("%I64d%d", &h, &x);
            if (hurt[n] - hurt[x - 1] < h) 
                ans++;
        } 
        printf("%d\n", ans);
    }   
    return 0;
}
