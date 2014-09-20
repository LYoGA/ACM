#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1000;

ll arr[MAXN];
ll n;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    while (scanf("%lld", &n) && n) {
        memset(arr, 0, sizeof(arr)); 
        int cnt = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                arr[cnt++] = i; 
                arr[cnt++] = n / i;
            }  
        }
        if (arr[cnt - 1] == arr[cnt - 2])
            cnt--;
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = i; j < cnt; j++) {
                if (((arr[i] * arr[j]) / gcd(arr[i], arr[j])) == n)  {
                    ans++; 
                }
            }
        }

        printf("%lld %d\n", n, ans); 
    }
    return 0;
}
