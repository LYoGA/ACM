#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;

int main() {
    int cas;
    int t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &m, &n);
        printf("Case %d:\n", t++);
        int k = 2;
        int ans = INF;
        while (m != 1) {
            int cnt = 0; 
            while (m % k == 0) {
                m /= k; 
                cnt++;
            } 
            if (cnt) {
                int a = 0;
                for (int i = 0; i <= n; i += k) {
                    if (i % k == 0 && i != 0) {
                        int temp = i;
                        while (temp % k == 0) {
                            a++; 
                            temp /= k; 
                        }  
                    } 
                }
                a = a / cnt;
                ans = min(ans, a);
            }
            k++;
        }
        if (ans)
            printf("%d\n", ans); 
        else
            printf("Impossible to divide\n");
    } 

    return 0;
}
