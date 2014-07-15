#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010

using namespace std;

int f[N * 2]; 
int n, m, a, b;

void init(int n) {
    for (int i = 0; i < n; i++) {
        f[i] = i; 
        f[i + n] = i + n;
    }
}

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

void setFriends(int a, int b) {
    int af = getFather(a);
    int bf = getFather(b);
    int ae = getFather(a + n);
    int be = getFather(b + n);
    if (af == be || bf == ae) {
        printf("-1\n");
        return; 
    }
    f[af] = bf;
    f[ae] = be; 
}
 
void setEnemies(int a, int b) {
    int af = getFather(a);
    int bf = getFather(b);
    int ae = getFather(a + n);
    int be = getFather(b + n);
    if (af == bf || ae == be) { 
        printf("-1\n"); 
        return; 
    }
    f[af] = be; 
    f[bf] = ae;
}

void areFriends(int a, int b) {
    int pa = getFather(a);
    int pb = getFather(b);
    if (pa == pb) 
        printf("1\n");
    else 
        printf("0\n");
}
 
void areEnemies(int a, int b) {
    int pa = getFather(a);
    int pb = getFather(b + n);
    if (pa == pb)
        printf("1\n");
    else
        printf("0\n");
}

int main() {
    scanf("%d", &n);
    memset(f, 0, sizeof(f));
    init(n);
    while (scanf("%d %d %d", &m, &a, &b) && (m || a || b)) {
        if (m == 1)  
            setFriends(a, b);        
        else if (m == 2) 
            setEnemies(a, b); 
        else if (m == 3) 
            areFriends(a, b); 
        else if (m == 4) 
            areEnemies(a, b); 
    }
    return 0;
}
