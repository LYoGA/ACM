#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct Node{
	char data;
	int left;
	int right;
};

stack<int> s;
queue<int> q;
Node arr[10005];
char str[10005];
char answer[10005];
int cnt;

void bfs(int root) {
	while (!q.empty())
		q.pop();
	q.push(root);
	answer[cnt++] = arr[root].data;//先将头节点存起来

	while (!q.empty()) {
		int t = q.front();	
		q.pop();	
		if (arr[t].left != -1) {
			answer[cnt++] = arr[arr[t].left].data;
			q.push(arr[t].left);	
		}	
		if (arr[t].right != -1) {
			answer[cnt++] = arr[arr[t].right].data;
			q.push(arr[t].right);	
		}
	}
}//层次遍历

void Build() {
	while (!s.empty())
		s.pop();
	for(int i = 0; i < strlen(str); i++) {
		if (islower(str[i])) {	
			s.push(i);
			arr[i].data = str[i];
			arr[i].left = -1;
			arr[i].right = -1;
		}//遇到小写字母就将其压入栈内
		else {
			int r = s.top();	
			s.pop();	
			int l = s.top();	
			s.pop();
			arr[i].data = str[i];
			arr[i].left = l;
			arr[i].right = r;
			s.push(i);
		}//遇到大写字母，就将栈顶的头两个节点取出，赋给新节点的左右儿子，并将新的节点压入栈内
	}
}//利用stack建二叉树

int main() {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%s", str);	
		cnt = 0;

		Build();				
		bfs(s.top());

		for(int i = cnt - 1; i >= 0; i--)//逆序输出
			printf("%c", answer[i]);
		printf("\n");
	}
	return 0;
}
