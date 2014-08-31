#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const double MAXN = 2000; 
const int N = 1000; 

int n;
double A, B, H[N];

int judge(double mid) {
    H[2] = mid;
    for (int i = 3; i <= n; i++) {
        H[i] = 2 * H[i - 1] - H[i - 2] + 2;
        if (H[i] < 0) 
            return false; 
    }
    B = H[n];
    return true;
}

int main() {
    while (scanf("%d %lf", &n, &A) != EOF) {
        memset(H, 0, sizeof(H));
        double L = 0, R = MAXN, mid;
        H[1] = A;
        while (R - L > 1e-8) {
            mid = (L + R) / 2;
          //  printf("%lf\n", mid);
            if (judge(mid)) 
                R = mid;
            else
                L = mid;
        }
        printf("%.2lf\n", B);
    }
    return 0;
}

