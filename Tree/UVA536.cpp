#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node *left, *right;
}Node;

Node *root;

char s1[100], s2[100];

void BuildTree(Node *&T, int n, int m, int l) {
	if (l <= 0)	{
		T = NULL;	
		return ;	
	}
	else {
		T = (Node *)malloc(sizeof(Node));
		T->data = s1[n];
		int p = strchr(s2, s1[n]) - s2;	
		int LenF = p - m;
		BuildTree(T->left, n + 1, m, LenF);
		int LenR = l - 1 - LenF;
		BuildTree(T->right, n + LenF + 1, p + 1, LenR);
	}	
}

void dfs1(Node *T) {
	if (T != NULL) {
		dfs1(T->left);	
		dfs1(T->right);
		printf("%c", T->data);	
	}	
}

int main() {
	while (scanf("%s %s", s1, s2) == 2) {	
		int len = strlen(s1);
		BuildTree(root, 0, 0, len);	
		dfs1(root);	
		printf("\n");
	}
	return 0;
}
