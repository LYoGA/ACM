#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 10005;

int a[MAXN];

int main () {
    int k;
    while (scanf("%d", &k) && k) {
        int cnt = 0;
        for (int i = 1; i <= k; i++) {
            scanf("%d", &a[i]);  
            if (a[i] < 0) 
                cnt++;
        }
        if (cnt == k) 
            printf("0 %d %d\n", a[1], a[k]); 
        else {
            int Max, sum, s, e, start, end; 
            Max = sum = -MAXN;
            for (int i = 1; i <= k; i++)  {
                if (sum + a[i] < a[i]) {
                    sum = a[i]; 
                    s = e =  i;
                }
                else {
                    sum += a[i]; 
                    e++; 
                } 
                if (sum > Max) {
                    Max = sum; 
                    start = s;
                    end = e;
                }
            }
            printf("%d %d %d\n", Max, a[start], a[end]);
        }        
    }
    return 0;
}
