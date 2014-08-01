#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 1005;

int m, k, t;
int arr[MAXN], vis[MAXN];
ll ans, sum, Min;

int judge(ll x) {
    memset(vis, 0, sizeof(vis));
    ll s = 0;
    t = 0;
    int flag = 1;
    for (int i = m - 1; i >= 0; i--) {
        if (arr[i] > x) {
            flag = 0; 
            break;
        } 
        if (s + arr[i] > x) {
            vis[i] = 1;
            t++;
            s = arr[i];
            if (t > k - 1) {
                flag = 0; 
                break;
            }  
        }
        else  
            s += arr[i];   
    }    
    return flag;
}

int binary() {
    ll x = Min, y = sum;
    while (x < y) {
        ll mid = x + (y - x) / 2;
        if (judge(mid)) 
            y = mid;
        else
            x = mid + 1; 
    }
    return x;
}

void outPut() {
    judge(ans);
    int num = k - 1 - t;
    for (int i = 0; i < m; i++) {
        if (vis[i] == 0 && num) {
            vis[i] = 1; 
            num--; 
        }
    } 
    for (int i = 0; i < m - 1; i++) {
        printf("%d ", arr[i]);
        if (vis[i])
             printf("/ "); 
    } 
    printf("%d\n", arr[m - 1]);
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d %d", &m, &k);         
        ans = 0;
        Min = arr[0];
        for (int i = 0; i < m; i++) {
            scanf("%d", &arr[i]); 
            sum += arr[i]; 
            if (Min < arr[i])
                Min = arr[i];
        }

        ans = binary();
        outPut();
    }  
    return 0;
}
