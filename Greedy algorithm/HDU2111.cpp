#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;
int v, n, sum;

struct bag{
    int pi, mi;
}b[N];

bool cmp(const bag& a, const bag& b) {
    return a.pi > b.pi;
}

int main() {
    while (scanf("%d %d", &v, &n) && v) {
        for (int i = 0; i < n; i++) 
            scanf("%d %d", &b[i].pi, &b[i].mi);
        sort(b, b + n, cmp);
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (v >= b[i].mi) {
                sum += (b[i].pi * b[i].mi); 
                v -= b[i].mi;
            }
            else { 
                sum += (b[i].pi * v);
                break; 
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
