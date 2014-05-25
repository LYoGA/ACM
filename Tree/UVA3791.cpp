#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 15; 

struct node{
    int v;
    struct node *left, *right;
};

node * root1, *root2;

int n, a[N], b[N], cnt;
char s1[N], s2[N];

node* buildTree(node* root, int x) {
    if (root == NULL) {
        root = (node*)malloc(sizeof(node));
        root -> v = x; 
        root -> left = root -> right = NULL;
        return root;
    } 
    if (root -> v > x)
        root -> left = buildTree(root -> left, x);
    else
        root -> right = buildTree(root -> right, x);
    return root; 
}

void dfs(node* root, int *arr) {
    if (root == NULL)
        return;
    else {
        arr[cnt++] = root -> v;
        dfs(root -> left, arr);
        dfs(root -> right, arr); 
    }
}

void solve(int *a, int *b) {
    for (int i = 0; i < cnt; i++)
        if (a[i] != b[i]) {
            printf("NO\n");
            return; 
        }
    printf("YES\n");
    return;
}

int main() {
    while (scanf("%d", &n) && n) {
        memset(a, 0, sizeof(a));
        root1 = NULL;
        cnt = 0;
        scanf("%s", &s1); 
        int l1 = strlen(s1);
        for (int i = 0; i < l1; i++) {
            a[i] = s1[i] - '0';
            root1 = buildTree(root1, a[i]); 
        }
        dfs(root1, a);
        for (int i = 0; i < n; i++) {
            cnt = 0;
            memset(b, 0, sizeof(b));
            root2 = NULL;
            scanf("%s", &s2); 
            int l2 = strlen(s2);
            for (int j = 0; j < l2; j++) {
                b[j] = s2[j] - '0';
                root2 = buildTree(root2, b[j]); 
            }
            dfs(root2, b);
            solve(a, b);
        } 
    }
    return 0;
}
