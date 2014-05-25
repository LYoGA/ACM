#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 100005;

int a[MAXN];

int main () {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) 
            scanf("%d", &a[i]);
        int Max, sum, s, e, start, end;
        Max = sum = -MAXN;
        for (int i = 1; i <= n; i++) {
           // sum = max(sum + a[i], a[i]);
            if (sum + a[i] < a[i]) {
                sum = a[i];
                s = e = i;
            }
            else {
                sum = a[i] + sum; 
                e++; 
            }
            if (sum > Max) {
                Max = sum;
                start = s; 
                end = e;
            }
        }
        printf("Case %d:\n", t++);
        printf("%d %d %d\n", Max, start, end);
        if (cas)
            printf("\n");
    }
    return 0;
}
