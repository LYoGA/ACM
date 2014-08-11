#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n, m;

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        double ans = 0;
        for (int i = 1; i < n; i++) {
            double pos = (double)i / n * (n+m); 
            ans += fabs(pos - floor(pos+0.5) / (n+m));
        } 
        printf("%.4lf\n", ans*10000); 
    } 
    return 0;
}
