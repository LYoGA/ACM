#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

typedef struct TNode{
	char data;
	struct TNode *left, *right;
}Node;

char PreArray[100] = "DBACEGF";	//先序序列
char InArray[100] = "ABCDEFG";  //中序序列
char PostArray[100] = "ACBFGED";//后序序列

/*
PreIndex: 前序序列字符串中子树的第一个节点在PreArray[]中的下标 
InIndex:  中序序列字符串中子树的第一个节点在InArray[]中的下标 
PostIndex: 后序序列字符串中子树的第一个节点在PostArray[]中的下标
subTreeLen: 子树的字符串序列的长度 
PreArray： 先序序列数"组 
InArray：中序序列数组 
PostArray: 后序序列数组
*/  

//先序 + 中序 = 建树
void buildTree1(Node *&T, int PreIndex, int InIndex, int subTreeLen) {
	//字符串长度为0时，返回上一层
	if (subTreeLen <= 0) {
		T = NULL;	
		return;	
	}
	T = (Node *)malloc(sizeof(Node));
	//存节点
	T->data = PreArray[PreIndex];
	//找出节点在中序序列中的位置
	int p = strchr(InArray, PreArray[PreIndex]) - InArray;	
	//左子树的长度
	int LenF = p - InIndex; 
	//建立左子树
	buildTree1(T->left, PreIndex + 1, InIndex, LenF);
	//右子树的长度
	int LenR = subTreeLen - 1 - LenF;
	//建立右子树
	buildTree1(T->right, PreIndex + LenF + 1, p + 1, LenR);
}

//中序 + 后序 = 建树
void buildTree2(Node *&T, int PostIndex, int InIndex, int subTreeLen) {
	//字符串长度为0时，返回上一层	
	if (subTreeLen <= 0) {
		T = NULL;	
		return;
	}
	T = (Node *)malloc(sizeof(Node));
	//存节点
	T->data = PostArray[PostIndex];
	//找出节点在中序序列中的位置
	int p = strchr(InArray, PostArray[PostIndex]) - InArray; 
	//左子树的长度
	int LenF = p - InIndex;
	//建立左子树
	buildTree2(T->left, PostIndex - (subTreeLen - 1 - LenF) - 1, InIndex, LenF);
	//右子树的长度
	int LenR = subTreeLen - 1 - LenF;
	//建立右子树
	buildTree2(T->right, PostIndex - 1, p + 1, LenR);
}

//先序遍历
void preOrderVisit(Node *T) {
	if (T != NULL)	{
		printf("%c", T->data);	
		preOrderVisit(T->left);	
		preOrderVisit(T->right);		
	}
} 

//后序遍历
void posOrderVisit(Node *T) {
	if (T != NULL) {
		posOrderVisit(T->left);	
		posOrderVisit(T->right);	
		printf("%c", T->data);		
	}
}

int main() {
	Node *root1;	
	buildTree1(root1, 0, 0, strlen(InArray));
	posOrderVisit(root1);
	printf("\n");

	Node *root2;
	buildTree2(root2, strlen(PostArray) - 1, 0, strlen(InArray));
	preOrderVisit(root2);
	printf("\n");
	return 0;
}
