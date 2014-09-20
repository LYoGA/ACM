#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);    
        if (n == 1 || n == 2)  
            printf("0\n");
        else {
            int ans;
            if (n % 2 == 0) {
                ans = (n / 2) * (n / 2 - 1);
                printf("%d\n", ans);
            }
            else {
                ans = (n / 2) * (n / 2 - 1) / 2 + (n / 2) * (n / 2 + 1) / 2;
                printf("%d\n", ans); 
            } 
        } 
    }
    return 0;
}
