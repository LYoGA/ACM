#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, m;

struct food{
    int p, h;
}f[N];

bool cmp(const food& a, const food& b) {
    return a.p < b.p;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d %d", &n, &m);                 
        for (int i = 0; i < m; i++)
            scanf("%d %d", &f[i].p, &f[i].h);
        sort(f, f + m, cmp); 
        double sum = 0;
        for (int i = 0; i < m; i++) {
            if (n > 0) {
                if (n >= f[i].p * f[i].h) {
                    n -= f[i].p * f[i].h;
                    sum += f[i].h;
                } 
                else {
                    sum += (n / (f[i].p * 1.0)); 
                    n = 0;
                }
            }  
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}
