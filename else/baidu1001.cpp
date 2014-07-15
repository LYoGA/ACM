#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        double n, m, v, k, step; 
        int cnt, flag;
        scanf("%lf %lf %lf %lf", &n, &m, &v, &k); 
        cnt = 0;
        flag = 1;
        while (n > m) {
            if (m < v || m == (m - v) * k) {
                flag = 0; 
                break;
            }
            m = (m - v) *k;
            cnt++;
        }
        if (flag)
            printf("%d\n", cnt);
        else
            printf("-1\n" );
    }
    return 0;
}
