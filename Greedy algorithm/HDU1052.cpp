#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1005;

int a[N], b[N];

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &a[i]); 
        for (int i = 0; i < n; i++) 
            scanf("%d", &b[i]); 
        sort(a, a + n); 
        sort(b, b + n);
        int i, j, k, s;
        j = s = 0;
        k = n - 1;
        for (i = 0; i < n;) {
            if (a[i] > b[j]) {
                s++;
                i++; 
                j++; 
            }
            else if (a[n - 1] > b[k]){
                s++;   
                n--; 
                k--;
            } 
            else {
                if (a[i] < b[k]) 
                    s--; 
                k--;
                i++;
            }  
        }
        printf("%d\n", s * 200);
    }
    return 0;
}
