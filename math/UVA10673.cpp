#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int x, y, d;

void gcd(int a, int b, int &d, int &x, int &y) {
    if (!b) {
        d = a;
        x = 1; 
        y = 0;
    }
    else {
        gcd(b, a % b, d, y, x); 
        y -= x * (a / b);
    }
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n, m, a, b;
        scanf("%d %d", &n, &m);
        a = (int)floor(n / (m * 1.0)); 
        b = (int)ceil(n / (m * 1.0)); 
        gcd(a, b, d, x, y);
        int tx = x * (n / d);
        int ty = y * (n / d);
        printf("%d %d\n", tx, ty);
    }
    return 0;
}
