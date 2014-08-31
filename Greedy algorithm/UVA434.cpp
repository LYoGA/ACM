#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10;

int a[MAXN], b[MAXN], num1[MAXN], num2[MAXN];
int n;

int getMin() {
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    for (int i = 1; i <= n; i++) {  
        num1[a[i]]++;  
        num2[b[i]]++;  
    }  
    int sum = 0;  
    for (int i = 1; i <= MAXN; i++)  
        sum += max(num1[i], num2[i]) * i;  
    return sum;
}

int getMax() {
    int cnt1, cnt2, sum = 0;
    while (1) {
        cnt1 = 0;
        for (int i = 1; i <= MAXN; i++)
            if (a[i]) {
                cnt1++;
                a[i]--;
            }
        cnt2 = 0;
        for (int i = 1; i <= MAXN; i++) 
            if (b[i]) {
                cnt2++; 
                b[i]--; 
            }
        if (!cnt1 && !cnt2) break;
        sum += cnt1 * cnt2; 
    }
    return sum;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);         
        for (int i = 1; i <= n; i++)  
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)  
            scanf("%d", &b[i]);
        int Min = getMin();
        int Max = getMax();
        printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", Min, Max - Min);
    }
    return 0;
}
