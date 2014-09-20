#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int cas; 
    scanf("%d", &cas);
    while (cas--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        
        int cnt = 0;
        for (int i = 1; a * i < c; i++) {
            if ((c - a * i) % b == 0)
                cnt++;
        }

        printf("%d\n", cnt);
    }
    return 0;
}
