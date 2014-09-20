#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

typedef unsigned long long ull;

const int MAXN = 100;

int vis[MAXN];

set<ull> arr;
set<ull>::iterator it;

void init() {
    memset(vis, 0, sizeof(vis));    
    for (int i = 2; i < MAXN; i++) {
        if (!vis[i])
        for (int j = i * 2; j < MAXN; j += i)
            vis[j] = 1;;
    }
}

ull pow(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    ull a = pow(n, k / 2);
    ull ans = a * a;
    if (k % 2)
        ans = ans * n;
    return ans;
}

int main() {
    init();
    arr.clear();
    arr.insert(1);

    double lmax = log(pow(2.0, 64) - 1);
    for (int i = 2; i < (1 << 16); i++) {
        int l = ceil(lmax / log(i)); 
        for (int j = 4; j < l; j++) {
            if (vis[j]) {
                ull num = pow(i, j); 
                if (!arr.count(num)) 
                    arr.insert(num);
            } 
        }  
    }

    for (it = arr.begin(); it != arr.end(); it++)
        cout << *it << endl;
    return 0;
}
