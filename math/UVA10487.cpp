#include <iostream> 
#include <cstdio> 
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 5001500 
using namespace std;

int a[N], c[N]; 
int n, m, cnt;

int deal(int d) {
    int x = 0, y = cnt - 1, z; 
    while (x < y - 1) {
        z = (y + x) / 2; 
        if (c[z] > d) 
            y = z;
        else if (c[z] < d)
            x = z;
        else {
            x = z; 
            break; 
        }
    }
    return x;
}

int main () { 
    int t = 0; 
    while (scanf("%d", &n) && n) { 
        for (int i = 0; i < n; i++) 
            scanf("%d", &a[i]); 
        cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                c[cnt++] = a[i] + a[j];
        sort(c, c + cnt);
        int num;
        printf("Case %d:\n", ++t);
        scanf("%d", &m);
        while (m--) {
            int q;
            scanf("%d", &q);
            if (q < c[0])
                num = c[0];
            else if (q > c[cnt - 1])
                num = c[cnt - 1];
            else {
                int sum, k, k1, k2;
                k = deal(q);
                k1 = c[k] - q;
                k2 = c[k + 1] - q;
                if (abs(k1) > abs(k2))
                    num = c[k + 1];
                else
                    num = c[k];  
            }
            printf("Closest sum to %d is %d.\n", q, num); 
        }
    }
    return 0;
}
