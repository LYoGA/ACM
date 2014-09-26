#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 6;

struct node{
    node() {
        memset(arr, 0, sizeof(arr));
        d = 0; 
    }
    int arr[MAXN], d;
}s, e;

int vis[MAXN * 200000];

int change(node a) {
    int num = 0;
    for (int i = 0; i < MAXN; i++) {
        num = num * 10 + a.arr[i]; 
    }
    return num;
}

bool judge(node a, node b) {
    for (int i = 0; i < MAXN; i++)
        if (a.arr[i] != b.arr[i])
            return false;
    return true;
}

node turn(node a, int i) {
    node c;
    if (i == 1) {
        c.arr[0] = a.arr[3];
        c.arr[1] = a.arr[2];
        c.arr[2] = a.arr[0];
        c.arr[3] = a.arr[1];
        c.arr[4] = a.arr[4];
        c.arr[5] = a.arr[5]; 
    }
    if (i == 2) {
        c.arr[0] = a.arr[2];
        c.arr[1] = a.arr[3];
        c.arr[2] = a.arr[1];
        c.arr[3] = a.arr[0]; 
        c.arr[4] = a.arr[4];
        c.arr[5] = a.arr[5]; 
    }
    if (i == 3) {
        c.arr[0] = a.arr[5];
        c.arr[1] = a.arr[4];
        c.arr[2] = a.arr[2];
        c.arr[3] = a.arr[3]; 
        c.arr[4] = a.arr[0];
        c.arr[5] = a.arr[1]; 
    }
    if (i == 4) {
        c.arr[0] = a.arr[4];
        c.arr[1] = a.arr[5];
        c.arr[2] = a.arr[2];
        c.arr[3] = a.arr[3]; 
        c.arr[4] = a.arr[1];
        c.arr[5] = a.arr[0];
    }
    return c;
}

int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<node> q;
    q.push(s);
    node tmp; 
    vis[change(s)] = 1;
    while (!q.empty()) {
        tmp = q.front(); 
        q.pop();            
        if (judge(tmp, e)) {
            return tmp.d;
        }
        for (int i = 1; i <= 4; i++) {
            node c;
            c = turn(tmp, i);
            if (!vis[change(c)]) {
                c.d = tmp.d + 1; 
                vis[change(c)] = 1;
                q.push(c);
            } 
        }
    } 
    return -1;
}

int main() {
    while (scanf("%d", &s.arr[0]) != EOF) {
        for (int i = 1; i < MAXN; i++) 
            scanf("%d", &s.arr[i]);
        for (int i = 0; i < MAXN; i++) 
            scanf("%d", &e.arr[i]);

        printf("%d\n", bfs());
    }    
    return 0;
}
