#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f;

int n, m;

int main() {
    int t = 0;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (t)
            printf("\n");
        t = 1;
        double k = n / (m * 1.0), r = INF;
        for (int i = 1; i <= m; i++) {
            int j = i * k + 0.5; 
            double temp = fabs(j / (i * 1.0) - k);
            if (temp < r) {
                r = temp; 
                printf("%d/%d\n", j, i); 
            }  
        }  
    }
    return 0;
}
