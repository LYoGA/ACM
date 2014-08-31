#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n;

int main() {
    while (scanf("%d", &n) != EOF) {
        int ans = n - 1 + (int)(ceil(log(n) / log(2))) - 1;
        printf("%d\n", ans); 
    }    
    return 0;
}
