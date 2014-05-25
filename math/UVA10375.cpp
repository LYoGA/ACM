#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 1000000;

int c[N];

int main () {
    int p, q, r, s;
    while (scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
        double sum = 1.0;
        for (int i = 1, j = 1; i <= q || j <= s; i++, j++) {
            if (i <= q)
                sum = sum * (p - i + 1) / i;
            if (j <= s)
                sum = sum * j / (r - j + 1);
        }
        printf("%.5lf\n", sum);
    }
    return 0;
}
