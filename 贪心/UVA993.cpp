#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100000

using namespace std;

int arr[N];

int main () {
    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);         
        if (m == 1)
            printf("1\n");
        else {
            int cnt = 0, num = 9;  
            while (num > 1) {
                while (m % num == 0) {
                    arr[cnt++] = num; 
                    m /= num; 
                } 
                num--;
            }
            if (m != 1) 
                printf("-1\n");
            else {
                for (int i = cnt - 1; i >= 0; i--) 
                    printf("%d", arr[i]);
                printf("\n");
            } 
        }
    }
    return 0;
}
