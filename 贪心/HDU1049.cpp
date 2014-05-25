#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, u, d, cnt;

int main() {
    while (scanf("%d %d %d", &n, &u, &d) && n && u && d) {
        int a, flag;
        cnt = a = flag = 0;
        while (!flag) {
            a += u;
            cnt++;
            if (a < n) { 
                a -= d; 
                cnt++; 
            }
            else
                flag = 1;
        }  
        printf("%d\n", cnt);
    }    
    return 0;
}
