#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int arr[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]);
        int sum = 0;   
        for (int i = 0; i < n; i++)
            sum ^= arr[i];
        if (sum == 0)
            printf("Lose\n");
        else
            printf("Win\n");
    }
    return 0;
}
