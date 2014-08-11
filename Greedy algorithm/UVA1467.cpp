#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 505;

struct task{
    int s, d;
}t[MAXN];

int n, p;

int cmp(task a, task b) {
    if (a.d != b.d)
        return a.d < b.d;
    else
        return a.s < b.s;
}

int deal(int x) {
    int cnt = 0, a = 0, b = 0, temp;
    for (int i = 0; i <= p; i++) {
        if (x == i)
            continue;
        cnt += t[i].s; 
        temp = max(cnt - t[i].d, 0);
        if (temp > a) {
            b = a;
            a = temp; 
        }
        else if (temp > b) 
            b = temp;  
    }
    cnt += t[x].s; 
    temp = max(cnt - t[x].d, 0);
    if (temp > a) {
        b = a;
        a = temp; 
    }
    else if (temp > b) {
        b = temp; 
    } 
    return a + b;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) 
            scanf("%d%d", &t[i].s, &t[i].d);
        sort(t, t + n, cmp); 

        int cnt = 0, a = 0, b = 0; 
        for (int i = 0; i < n; i++) {
            cnt += t[i].s; 
            int temp = max(cnt - t[i].d, 0);
            if (temp > a) {
                b = a;
                a = temp; 
                p = i;
            }
            else if (temp > b) {
                b = temp; 
                p = i;
            } 
        }

        int ans = a + b;;
        for (int i = 0; i < p; i++)
            ans = min(ans, deal(i));
        printf("%d\n", ans);
    }
    return 0;
}
