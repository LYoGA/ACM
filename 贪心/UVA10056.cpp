#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const double N = 1e-9;

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n, m, i = 0;
        double f, ans, p;
        scanf("%d %lf %d", &n, &f, &m); 
        m -= 1, p = 1, ans = 0;
        while (p > N) {
            p = f * pow(1 - f, i * n + m); 
            ans += p;
            i++;
        } 
        printf("%.4lf\n", ans);
    }
    return 0;
}
