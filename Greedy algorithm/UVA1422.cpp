#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 10000000;
const int MAXN = 10005;

struct Work{
    int r, d, w;
    friend bool operator < (Work a, Work b) {
        return a.d > b.d;
    }
}work[MAXN];

int n;

int cmp(Work a, Work b) {
    return a.r < b.r;
}

int judge(int mid) {
    priority_queue<Work> q;
    Work state;
    int cnt = 0;
    for (int i = 1; i <= 20000; i++) {
        if (!q.empty()) {
            state = q.top();
            if (state.d < i) {
                return false;  
            }
        }
        while (cnt < n && work[cnt].r + 1 <= i) {
            q.push(work[cnt++]); 
        }
        int sum = mid;
        while (sum && !q.empty()) {
            state = q.top();
            q.pop();
            if (sum < state.w) {
                state.w -= sum;
                sum = 0;
                q.push(state);
            } 
            else 
                sum -= state.w; 
            if (cnt == n && q.empty()) 
                return true;
        }  
    }
    return false;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &work[i].r, &work[i].d, &work[i].w);

        sort(work, work + n, cmp);
        int L = 0, R = N, mid;
        while (L < R) {
            mid = L + (R - L) / 2; 
            if (judge(mid)) 
                R = mid;
            else
                L = mid + 1; 
        }   
        printf("%d\n", L);
    }
    return 0;
}

