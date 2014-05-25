#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100005
using namespace std;

struct node{
    int v;
    struct node *left, *right;
};

node* root;

int n, arr[N];

node *buildTree(node* root, int x) {
    if (root == NULL) {
        root = (node *)malloc(sizeof(node)); 
        root -> v = x;
        root -> left = NULL;
        root -> right = NULL;
        return root;
    }
    if (root -> v > x) 
        root -> left = buildTree(root -> left, x); 
    else 
        root -> right = buildTree(root -> right, x);
    return root;
}

void dfs(node* root, int x) {
    if (root == NULL)
        return;
    else {
        if (x != 1)
            printf(" %d", root -> v); 
        else
            printf("%d", root -> v);
        dfs(root -> left, 2);
        dfs(root -> right, 2); 
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        root = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]); 
            root = buildTree(root, arr[i]); 
        }
        dfs(root, 1);
        printf("\n");
    }
    return 0;
}
