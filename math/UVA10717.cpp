#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 55;
const int INF = 0x3f3f3f3f;

int v[N], t[N];

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm_gcd(long long a, long long b, long long c, long long d) {
    long long temp;
    temp = a / gcd(a, b) * b;
    temp = temp / gcd(temp, c) * c;
    temp = temp / gcd(temp, d) * d;
    return temp;
}

int main () {
    int n, m;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]); 
        long long low, high;
        while (m--) {
            int a;
            scanf("%d", &a);
            low = 0;
            high = INF;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) { 
                        for (int l = k + 1; l < n; l++) {
                            long long ans = lcm_gcd(v[i], v[j], v[k], v[l]);                             
                            if (ans < a && a - a % ans > low) 
                                low = a - a % ans; 
                            if ((ans - a % ans) % ans + a < high) 
                                high = (ans - a % ans) % ans + a; 
                        }
                    }
                }         
            }
            printf("%lld %lld\n", low, high);
        }
    }
    return 0;
}
