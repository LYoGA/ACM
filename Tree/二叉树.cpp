#include <iostream>
#include <stdio.h>
#include <math.h>
#define N 10000
using namespace std;

int tree[N];
int data[N];
int n, p;

void build(int i) {
    if (2 * i < pow(2, n))
        build(2 * i);
    tree[p++] = data[i];
    if (2 * i + 1 < pow(2, n))
        build(2 * i + 1);
}

void preOrder(int a, int d) {
    if (d > n)
        return;
    else {
        printf("%d ", tree[a]); 
        preOrder(a * 2, d + 1); 
        preOrder(a * 2 + 1, d + 1);     
    }
}
 
void inOrder(int a, int d) {
    if (d > n)
        return;
    else {
        preOrder(a * 2, d + 1); 
        printf("%d ", tree[a]); 
        preOrder(a * 2 + 1, d + 1);  
    }
}
 
void posOrder(int a, int d) {
    if (d > n)
        return;
    else {
        preOrder(a * 2, d + 1); 
        preOrder(a * 2 + 1, d + 1); 
        printf("%d ", tree[a]); 
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i < pow(2, n); i++)
        data[i] = i;
    p = 1;
    build(1);
    preOrder(1, 1); cout << endl;
    inOrder(1, 1); cout << endl;
    posOrder(1, 1); cout << endl;
    return 0;
}
