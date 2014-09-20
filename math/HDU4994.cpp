#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef __int64 ll;
//typedef long long ll;
const int MAXN = 1005;

int arr[MAXN];

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n; 
        scanf("%d", &n);
        ll a;
        for (int i = 0; i < n; i++)
            scanf("%I64d", &arr[i]); 

        int cnt = 0, flag = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1)
                cnt++;
            if (arr[i] != 1) {
                flag = 0;
                break;
            }
        }

        if (cnt % 2 == 0) {
            if (flag)
                printf("No\n");
            else 
                printf("Yes\n");
        }
        else {
            if (flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
