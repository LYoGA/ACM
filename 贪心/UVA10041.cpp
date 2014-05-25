#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 505

using namespace std;

int arr[N];

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n; 
        scanf("%d", &n);
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]);
        sort(arr, arr + n);
        int sum = 0;
        int half = arr[(n - 1) / 2];
        for (int i = 0; i < n; i++) {
            if (i != (n - 1) / 2)
                sum += abs(half - arr[i]);
        }
        printf("%d\n", sum); 
    }
    return 0;
}
