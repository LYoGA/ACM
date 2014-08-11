#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int x[MAXN], y[MAXN];
int n, d, r;


int main() {
    while (scanf("%d%d%d", &n, &d, &r) != EOF) {
        if (!n && !d && !r) 
            break;
        for (int i = 0; i < n; i++) 
            scanf("%d", &x[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &y[i]);
        sort(x, x + n);
        sort(y, y + n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int temp = x[i] + y[n - 1 - i];
            if (temp - d > 0) 
                sum += temp - d; 
        }
        printf("%lld\n", sum * r); 
    }
    return 0;
}
