#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n, t = 1;
    while (scanf("%d", &n) != EOF) {
        if (n < 1)
            break;
        int cnt = 1, num = 0;
        while (cnt < n) {
            num++;
            cnt *= 2;  
        }  
        printf("Case %d: %d\n", t++, num);
    }
    return 0;
}
