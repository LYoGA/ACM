#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int const MAXN = 105;

int n;

void outPut() {
    printf("%d\n", n * 3 / 2);
    for (int i = 1; i <= n; i++) {
        int a = i;
        int b = i + 1;
        if (b > n)
            b %= n;
        printf("%d %d\n", a, b);  
    } 
    for (int i = 1; i <= n / 2; i++)
        printf("%d %d\n", i, i + (n / 2));
}

int main() {
    while (scanf("%d", &n) && n) {
        if (n < 4 || n % 2) 
            printf("Impossible\n");
        else 
            outPut();         
    }
    return 0;
}
