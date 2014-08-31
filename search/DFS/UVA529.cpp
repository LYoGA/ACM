#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

int arr[MAXN];
int n, depth, flag;

void init() {
    memset(arr, 0, sizeof(arr));
    arr[0] = 1;
    depth = 0;
    int temp = 1;
    while (temp < n) { 
        temp = temp << 1;
        depth++;
    }
}

int dfs(int cur) {
    if (cur >= depth) {
        if(arr[cur] == n)
            return true;
        return false;
    }
    if (arr[cur] << (depth - cur + 1) < n)
        return false;
    for (int i = 0; i <= cur; i++) 
        for (int j = i; j <= cur; j++) {
            int sum = arr[i] + arr[j];
            if (sum > arr[cur] && sum <= n) {
                arr[cur + 1] = sum;
                if (dfs(cur + 1))
                    return true;
            } 
        }  
    return false;
}

int main() {
    while (scanf("%d", &n) && n) {
        init();
        while (!dfs(0)) 
            depth++; 
        printf("%d", arr[0]);
        for (int i = 1; i <= depth; i++) 
            printf(" %d", arr[i]);  
        printf("\n");
    }    
    return 0;
}
