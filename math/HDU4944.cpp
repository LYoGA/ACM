#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned __int64 ull;
const int MAXN = 500000;
const ull MOD = (ull)1 << 32;

ull  ans[MAXN + 5], sum[MAXN + 5];
int n;

void init() {
    memset(ans, 0, sizeof(ans));
    memset(sum , 0, sizeof(sum));
    for (ull i = 1; i <= MAXN; i++)
        for (ull j = i; j <= MAXN; j += i)
            sum[j] += (j / i + 1) * (j / i) / 2;
    for (ull i = 1; i <= MAXN; i++) {
        ans[i] = ans[i - 1] + sum[i] * i;  
        ans[i] %= MOD; 
    }
}

int main() {
    int t = 1, cas;
    init();
    scanf("%d", &cas); 
    while (cas--) {
        scanf("%d", &n);
        printf("Case #%d: %I64u\n", t++, ans[n]);  
    }  
    return 0;
}
