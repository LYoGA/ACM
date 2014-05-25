#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int pow_mod(int a, int n, int m) {
    a %= m;
    if (n == 0)
        return 1;
    if (n % 2)
        return pow_mod(a * a, n / 2, m) * a % m;
    else
        return pow_mod(a * a, n / 2, m);
}

int solve(int a, int b) {
    double ans = b * log(a) / log(10);
    ans = ans - (int)ans;
    return (int)((pow(10, ans) + 1e-9) * 100);
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n, k; 
        scanf("%d %d", &n, &k); 
        int front = solve(n, k);
        int rear = pow_mod(n, k, 1000);
        printf("%d...%03d\n", front, rear);        
    }
    return 0;
}
