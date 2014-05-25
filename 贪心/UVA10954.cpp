#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100005

using namespace std;

int arr[N]; 
int main() {
    int n;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]);             
        sort(arr, arr + n);
        long long sum = 0;
        int cnt = 0;
        while (cnt != n - 1) {
            int num = arr[cnt] + arr[cnt + 1];
            sum += num; 
            arr[cnt + 1] = num;
            arr[cnt] = 0;
            for (int j = cnt + 1; j < n; j++) {
                if (num < arr[j]) {
                    for (int k = cnt + 1; k < j - 1; k++) 
                        arr[k] = arr[k + 1] ;
                    arr[j - 1] = num;    
                    break; 
                 } 
                else if (j == n - 1) {
                    for (int k = cnt + 1; k < n - 1; k++) 
                        arr[k] = arr[k + 1] ;
                    arr[n - 1] = num;    
                    break;   
                }
            }
            cnt++;
        }
        printf("%lld\n", sum);
    }
    return 0;
}

