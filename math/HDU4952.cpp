#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

typedef __int64 LL;

LL x, k;

int main(){
    L x, k;
    int t = 1;
    while (cin >> x >> k && x){
        LL d;
        d = x;
        for (int i = 2; i <= k; i++){
            d = d - d / i;
            if (d < i) 
                break;
        }
        printf("Case #%d: %I64d\n", t++, k * d);
    }
    return 0;
}
