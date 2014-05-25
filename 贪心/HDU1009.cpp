#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1005;

struct state{
    double a, b, c;
}s[N];

bool cmp(const state& a, const state& b) {
    return a.c > b.c; 
}

int main() {
    int m, n;
    double sum;
    while (scanf("%d %d", &m, &n)) {
        if (m == -1 && n == -1) 
            break;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &s[i].a, &s[i].b); 
            s[i].c = s[i].a / s[i].b;
        } 
        sort(s, s + n, cmp);
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (m < s[i].b) {     
                sum += s[i].a * (m / s[i].b);
                break;
            }
            m -= s[i].b; 
            sum += s[i].a; 
        }
        printf("%.3lf\n", sum);
    }
    return 0;
}

