#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a, b;

ll solve(ll left) {
    ll ans = 0, num = 1, right = 0, mid;
    while (left >= 10) {
        mid = left % 10; 
        left /= 10;
        if (mid)
            ans += left * num;
        else
            ans += (left - 1) * num + right + 1;
        right += mid * num;
        num *= 10; 
    }
    return ans;
}

int main() {
    while (scanf("%lld%lld", &a, &b)) {
        if (a == -1 && b == -1)
            break;
        ll ans = solve(b) - solve(a - 1); 
        if (a == 0)
            ans++;
        printf("%lld\n", ans); 
    }    
    return 0;
}
