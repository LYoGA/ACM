#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int g, l;

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &g, &l); 
        if (g > l) {
            swap(g, l);
        }
        if (l % g == 0) 
            printf("%d %d\n", g, l);
        else
            printf("-1\n");
    } 
    return 0;
}
