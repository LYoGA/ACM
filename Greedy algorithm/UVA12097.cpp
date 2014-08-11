#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);
const int MAXN = 10005;

int n, f;
double A[MAXN];

bool ok(double area) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += floor(A[i] / area);
    return sum >= f + 1;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &f); 
        double maxa = -1;
        for (int i = 0; i < n; i++) {
            int r; 
            scanf("%d", &r);
            A[i] = PI * r * r;
            maxa = max(maxa, A[i]);
        }
        double L = 0, R = maxa;
        while (R - L > 1e-5) {
            double M = (L + R) / 2; 
            if (ok(M)) 
                L = M;
            else
                R = M;
        }
        printf("%.5lf\n", L);  
        cout << PI << endl;
    } 
    return 0;
}
