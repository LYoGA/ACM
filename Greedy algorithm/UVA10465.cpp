#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int m, n, t;

int main() {
    while (scanf("%d %d %d", &m, &n, &t) != EOF) {
        if (m > n) 
            swap(m, n); 
        int Max = t / m;  
        int beer = t - (m * Max);
        if (beer == 0) {
            printf("%d\n", Max);
            continue; 
        }
        for (int i = 1; i <= t / n; i++) {
            int tempMax = (t - i * n) / m + i; 
            int tempbeer = t - ((tempMax - i) * m + n * i);
            if (tempbeer >= 0 && tempbeer < beer) {
                Max = tempMax; 
                beer = tempbeer; 
            }
            if (tempbeer == 0) 
                break;  
        }  
        printf("%d", Max);
        if (beer != 0)
            printf(" %d", beer);
        printf("\n");
    } 
    return 0;
}
