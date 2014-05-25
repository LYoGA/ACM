#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000005
using namespace std;

int arr[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]); 
        sort(arr, arr + n);
        int max, min, sum, count = 0;
        if (n % 2) {
            sum = 1;     
            min = arr[n / 2];
            max = min;
        }
        else{
            sum = arr[n / 2] - arr[n / 2 - 1] + 1;
            min = arr[n / 2 - 1]; 
            max = arr[n / 2]; 
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] >= min && arr[i] <= max) 
                count++;
            if (arr[i] > max) 
                break;
        }
        printf("%d %d %d\n", min, count, sum);
    }
    return 0;
}
