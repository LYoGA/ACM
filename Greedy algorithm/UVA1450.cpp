#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5005;

int t;
int A[MAXN], B[MAXN];

int judge(int n) {
    int cura = 0, curb = 0, num = 0; 
    int a, b;
    for (int i = 0; i < t; i++) {
        cura += A[i]; 
        curb += B[i]; 
        a = max(cura - n, 0);
        b = max(curb - n, 0);
        if (a + b > num)
            return false; 
        if (cura > 0 && curb > 0 && cura + curb > num) 
            num++;   
        else if (cura > 0 && curb == 0)
            cura--;  
        else if (cura == 0 && curb > 0) 
            curb--;        
    }
    return true;
}

int main() {
    int cas; 
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &t);         
        for (int i = 0; i < t; i++) 
            scanf("%d%d", &A[i], &B[i]);

        int L = 1, R = MAXN * 20, mid;
        while (L < R) {
            mid = (R + L) / 2; 
            if (judge(mid)) 
                R = mid;
            else
                L = mid + 1; 
        }
        printf("%d\n", L - 1); 
    }
    return 0;
}
