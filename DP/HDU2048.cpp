#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 105;

int d[N][N], a[N][N]; 
int main () { 
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n; 
        scanf("%d", &n); 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= i; j++)
                scanf("%d", &a[i][j]);
        for (int i = n; i > 0; i--) {
            for (int j = 1; j <= i; j++) {
                if (i == n) 
                    d[i][j] = a[i][j];
                else
                    d[i][j] = a[i][j] + max(d[i + 1][j], d[i + 1][j + 1]); 
            }
        }
        printf("%d\n", d[1][1]);
    }
    return 0;
}
