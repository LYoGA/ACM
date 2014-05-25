#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long LL;
const int N = 65005;

int n, m, cnt;
int prime[N];

void P() {
    m = sqrt(N + 0.5);
    for (int i = 2; i < m; i++) 
        if (!prime[i]) {
            for (int j = i * i; j < N; j += i) 
                prime[j] = 1;
        } 
}

int judge(int n) {
    if (!prime[n])
        return 1;
    else
        return 0;
}

LL pow_mod(int a, int n, int m) {
    if (n == 1) 
        return a % m;
    LL x = pow_mod(a, n / 2, m);
    LL ans = (x * x) % m;
    if (n % 2 == 1)
        ans = ans * a % m;
    return ans; 
}

int main() {
    memset(prime, 0, sizeof(prime));
    P();
    while (scanf("%d", &n) && n) {
        int flag = judge(n); 
        if (flag) {
            printf("%d is normal.\n", n); 
            continue;
        }
        else {
            int flag1 = 1;
            for (int i = 2; i < n; i++) {
                int k = pow_mod(i, n, n);  
                if (k != i) {
                    flag1 = 0; 
                    break; 
                }
            } 
            if (flag1)
                printf("The number %d is a Carmichael number.\n", n);
            else
                printf("%d is normal.\n", n);
        } 
    }
    return 0;
} 
