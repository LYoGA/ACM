#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int a[MAXN], b[MAXN], num1[MAXN], num2[MAXN];

int main() {
    int w, d;
    while (scanf("%d%d", &w, &d) && w && d) {
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        for (int i = 1; i <= w; i++) {
            scanf("%d", &a[i]); 
            num1[a[i]]++;
        }
        for (int i = 1; i <= d; i++) {
            scanf("%d", &b[i]); 
            num2[b[i]]++;
        }
        int sum = 0;
        for (int i = 1; i <= MAXN; i++)
            sum += max(num1[i], num2[i]) * i;
        printf("%d\n", sum); 
    }
    return 0;
}
