#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;
int n, arr[N];

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]); 
        int cnt = 0, max, m = n;
        while (m) {
            max = 30000;
            for (int i = 0; i < n; i++) {
                if (arr[i] > 0 && arr[i] < max) {
                    max = arr[i];
                    arr[i] = -1; 
                    m--;
                } 
            }  
            cnt++;
        } 
        printf("%d\n", cnt);
    }
    return 0;
}
