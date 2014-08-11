#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n; 
    while (scanf("%d", &n) && n) {
        if (n <= 3)
            printf("1\n");
        else if (n == 4)
            printf("2\n");
        else
            printf("%d\n", n);
    }
    return 0;
}
