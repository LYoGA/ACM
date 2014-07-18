#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10005;
const int N = 22;

int n, coin[N];
long long d[MAXN];

void init() {
    for (int i = 1; i < N; i++)
        coin[i] = i * i * i;
}

void dp() {
    memset(d, 0, sizeof(d));
    d[0] = 1;
    for (int i = 1; i < N; i++) 
        for (int j = coin[i]; j <= MAXN; j++) 
            if (j >= coin[i]) 
                d[j] += d[j - coin[i]]; 
}

int main() {
    init();
    dp();
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", d[n]); 
    }
    return 0;
}
