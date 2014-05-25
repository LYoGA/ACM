#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main () {
    int n, m, cnt, t = 1; 
    long long sum;
    while (scanf("%d", &n) && n) {
        int flagn = n;
        sum = cnt = 0;     
        m = sqrt(n) + 2;
        for (int i = 2; i <= m; i++) {
            if (flagn % i == 0) {
                cnt++; 
                int temp = 1; 
                while (flagn % i == 0) {
                    temp *= i; 
                    flagn /= i; 
                }
                sum += temp; 
            } 
        }
        if (flagn == n) 
            sum = (long long)n + 1; 
        else if (cnt == 1 || flagn != 1) 
            sum += flagn; 
        printf("Case %d: %lld\n", t++, sum);
    }
    return 0;
}

