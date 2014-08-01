#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

int n, arr[MAXN];

int cmp(int a, int b) {
    return a > b;
}

int Havel_Hakimi() {
    for (int i = 0; i < n; i++) {
        sort(arr + i, arr + n, cmp); 
        if (arr[i] > n - 1 - i)
            return 0;
        for (int j = i + 1; j <= i + arr[i]; j++) {
            arr[j]--; 
            if (arr[j] < 0)
                return 0;
        } 
    }
    return 1;
}

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]);

        if (Havel_Hakimi()) 
            printf("Possible\n");
        else
            printf("Not possible\n"); 
    }
    return 0;
}
