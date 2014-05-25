#include <iostream>
#include <cstdio>
#include <cstring>

const int N = 105;
int n, arr[N];

int main() {
    int t = 1, cas;
    scanf("%d", &cas);
    memset(arr, 0, sizeof(arr));
    while (cas--) {
        scanf("%d", &n); 
        printf("Case #%d: ", t++);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        int cnt = 0; 
        while (n) {
            arr[cnt] = n % (-2); 
            n /= (-2); 
            if (arr[cnt] == -1) {
                arr[cnt] = 1; 
                n++; 
            }
            cnt++;
        }
        for (int i = cnt - 1; i >= 0; i--)
            printf("%d", arr[i]);
        printf("\n");
    }
    return 0;
}
