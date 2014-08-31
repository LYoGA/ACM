#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1005;
using namespace std;

int arr[MAXN];
int n, depth, num;

void init() {
    depth = 0;
    int temp = 1;
    while (n > temp) {
        temp = temp * 2; 
        depth++;
    }
}

int dfs(int cur, int d) {
    if (d >= depth) {
        if (cur == n) 
            return true;
        return false;
    }
    for (int i = num - 1; i >= 0; i--) {
        int Max = 0;
        for (int j = 0; j < num; j++) 
            Max = max(Max, arr[j]);
        if ((cur + Max) << (depth - d - 1) < n)
            return false;
        arr[num++] = cur + arr[i];
        if (dfs(cur + arr[i], d + 1))
            return true;
        num--;
        arr[num++] = cur - arr[i];
        if (dfs(cur - arr[i], d + 1))
            return true; 
        num--;
    }
    return false;
}

int main() {
    while (scanf("%d", &n) && n) {
        if (n == 1) {
            printf("0\n"); 
            continue;
        }
        init();
        while (1) {
            memset(arr, 0, sizeof(arr)); 
            arr[0] = num = 1;
            if (dfs(1, 0))
                break;
            depth++;
        }
        printf("%d\n", depth); 
    }    
    return 0;
}
