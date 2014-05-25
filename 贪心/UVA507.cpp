#include <iostream>
#include <cstdio>
#include <cstring>
#define N 20005

using namespace std;

int arr[N]; 

int main() {
    int b, t = 1;
    scanf("%d", &b);
    while (b--) {
        int s;
        scanf("%d", &s);
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= s - 1; i++) {
            scanf("%d", &arr[i]);
            arr[i] += arr[i - 1];
        }
        int max = -2147483646;
        int a = 0;
        int b = 0;
        int min = 0;
        for (int i = 1; i <= s - 1; i++) {
            int num = arr[i] - arr[min];
            if (num > max) {
                max = num;
                a = min;
                b = i;
            } 
            else if (num == max) { 
                if (a == min)
                    b = i;
                else if (b - a < i - min) {
                    a = min;
                    b = i; 
                }
            }
            if (arr[min] > arr[i]) 
                min = i; 
        }
        if (max > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", t++, a + 1, b + 1);
        else
            printf("Route %d has no nice parts\n", t++);
    }
    return 0;
}
