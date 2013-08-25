#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<ctype.h>
#define N 10005

typedef struct node{
	int data;
	struct node *left, *right;
}Node;

Node *Root;

char s1[N * 10], s2[N * 10]; 
int arr1[N * 10], arr2[N * 10];
int sum, min, t, cnt1, cnt2;

void put(char *s1, char *s2) {
	int len = strlen(s2);
	int num = 0; 
	cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < len; i++) {
		if(isdigit(s1[i])) {
			num = num * 10 + (s1[i] - '0');
			if (i == len - 1)	
				arr1[cnt1++] = num;	
		}
		else if (s1[i] == ' ') {
			arr1[cnt1++] = num;
			num = 0;
		}
	}
	num = 0;
	for(int i = 0; i < len; i++) {
		if(isdigit(s2[i])) {
			num = num * 10 + (s2[i] - '0');
			if (i == len - 1)	
				arr2[cnt2++] = num;
		}
		else if (s2[i] == ' ') {
			arr2[cnt2++] = num;
			num = 0;
		}
	}


}
void BuildTree(Node *&T, int n, int m, int l) {
	if (l <= 0)	{
		T = NULL;	
		return ;	
	}
	else {
		T = (Node *)malloc(sizeof(Node));
		T->data = arr2[n];	
		int p = 0;
		while ( arr1[p] != arr2[n])
			p++;
		int LenF = p - m;
		BuildTree(T->left, n - (l - LenF - 1) - 1, m, LenF);
		int LenR = l - 1 - LenF;
		BuildTree(T->right, n - 1, p + 1, LenR);
	}	
}

int dfs1(Node *T, int sum) {
	if ((T->left == NULL) && (T->right == NULL) && (sum < min)) {
		min = sum;
		t = T->data;
	}
	if (T->left != NULL) 
		dfs1(T->left, sum + T->left->data); 
	if (T->right != NULL) 
		dfs1(T->right, sum + T->right->data);
	return 0;
}

int main() {
	while (gets(s1) != NULL) {		
		gets(s2);
		sum = 0, min = 999999999;
		put(s1, s2);
		BuildTree(Root, cnt2 - 1, 0, cnt1);	
		dfs1(Root, Root->data);	
		printf("%d\n", t);
	}
	return 0;
}
