#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 100005

using namespace std;

int a[N];

int main () {
    int n;
    while (scanf("%d", &n) && n) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) 
            scanf("%d", &a[i]);
        long long ans = 0; 
        for (int i = 0; i < n - 1; i++) {
            ans += abs(a[i]);
            a[i + 1] += a[i];
        }       
        cout << ans << endl;
    }
    return 0;
}
