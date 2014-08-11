#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 5005;

struct Car{
    int l, r, id;
    friend bool operator < (const Car a, const Car b) {
        return a.r > b.r; 
    }
}x[MAXN], y[MAXN], c[MAXN];

int n;

int cmp(Car a, Car b) {
    return a.l < b.l;
}

int judge(Car *cur, int flag) {
    sort(cur, cur + n, cmp);
    priority_queue<Car> q;
    Car state;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (cnt < n && cur[cnt].l <= i + 1) 
            q.push(cur[cnt++]);
        if (q.empty()) {        
            return false; 
        }
        state = q.top(); 
        q.pop();
        if (state.r < i + 1) {
            return false; 
        }
        if (flag == 0)
            c[state.id].l = i + 1;
        else
            c[state.id].r = i + 1;
    }
    return true;
}

void outPut() {
    for (int i = 0; i < n; i++)
        printf("%d %d\n", c[i].l, c[i].r);
}

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {         
            scanf("%d%d%d%d", &x[i].l, &y[i].l, &x[i].r, &y[i].r);
            x[i].id = y[i].id = i;
        }
        if (judge(x, 0) && judge(y, 1))
            outPut();
        else
            printf("IMPOSSIBLE\n");
    }    
    return 0;
}
