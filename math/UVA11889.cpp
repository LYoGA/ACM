#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int a, c;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int cas;    
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &a, &c); 
        if (c % a != 0) {
            printf("NO SOLUTION\n"); 
        }
        else {
            int b = c / a;  
            int flag = 0;
            for (int i = b; i <= c; i += b) {
                if (b == i / gcd(i, a)) {
                    printf("%d\n", i); 
                    break;
                }
            } 
        } 
    }
    return 0;
}
