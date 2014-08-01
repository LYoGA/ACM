#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 20005;

int a[MAXN], b[MAXN];
int n, m;
long long sum;

int main() {
    while (scanf("%d %d", &n, &m) && n && m) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) 
            scanf("%d", &b[i]);
        sort(a, a + n); 
        sort(b, b + m);
        sum = 0;
        int cur = 0;
        for (int i = 0; i < m; i++) {
            if (b[i] >= a[cur]) {
                sum += b[i]; 
                cur++;
            }
            if (cur == n) 
                break;
        }

        if (cur == n)
            printf("%lld\n", sum);
        else
            printf("Loowater is doomed!\n");
    } 
    return 0;
}
