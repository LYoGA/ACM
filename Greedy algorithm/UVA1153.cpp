#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 800005;
const int N = 2000005;

struct order{
    int q, d;
}o[MAXN];

int n;

int cmp (order a, order b) {
    return a.d < b.d;
}

int solve() {
    priority_queue<int> Q; 
    int t = 0, temp;
    for (int i = 0; i < n; i++) {
        if (o[i].q + t <= o[i].d) {
            Q.push(o[i].q); 
            t += o[i].q;
        }
        else if (!Q.empty()){
            temp = Q.top(); 
            if (temp > o[i].q) {
                t = t - temp + o[i].q;              
                Q.pop();
                Q.push(o[i].q);
            }
        } 
    }   
    return Q.size();
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);         
        for (int i = 0; i < n; i++) 
            scanf("%d%d", &o[i].q, &o[i].d);
        sort(o, o + n, cmp); 
        printf("%d\n", solve()); 
        if (cas) 
            printf("\n");  
    }
    return 0;
}
