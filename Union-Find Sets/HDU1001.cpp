#include <iostream>
#include <cstdio>
#include <cstring>

#define max 50002

using namespace std;

int par[max], rank[max];

int find(int x) {
    if(par[x] == x)
        return x;
    int t = find(par[x]);
    rank[x] = (rank[par[x]] + rank[x]) % 3;
    par[x] = t;
    return t;
}

void uion(int d,int x,int y,int px,int py) {
    par[py] = px;
    rank[py] = (rank[x] - rank[y] + 3 + d - 1) % 3;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n, k, flag = 0;
        int x, y, d, f1, f2;
        scanf("%d %d", &n, &k);
        for (int i = 0;i <= n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
        while(k--) {
            scanf("%d%d%d",&d,&x,&y);
            if (x > n || y > n)
                flag++;
            else if(d == 2 && x == y)
                flag++;
            else {
                f1 = find(x);
                f2 = find(y);
                if(f1 == f2) {
                    if(d == 1 && rank[x] != rank[y])
                        flag++;
                    else {
                        if(d == 2 && rank[y] != (rank[x] + 1) % 3)
                            flag++;
                    }
                }
                else {
                    uion(d,x,y,f1,f2);
                }
            }
        }
        printf("%d\n",flag); 
    }
    return 0;
}

