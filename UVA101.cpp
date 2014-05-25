#include<stdio.h>
#include<string.h>

struct stack{
	int b[30];
	int num; 
}block[30];

int postion[30];

void turn_back(int x) {
	int pos, t, T, cnt = 0;
	t = postion[x];
	for(int i = 1; i <= block[t].num; i++) 
		if (block[t].b[i] == x) {	
			pos = i;//记录所要目标木块x在其所在堆中的位置	
			break;
		}		
	for(int i = pos + 1; i <= block[t].num; i++)	{
		T = block[t].b[i];	
		block[T].num++;	
		cnt++;	
		for(int j = block[T].num; j >= 2; j++)
			block[T].b[j] = block[T].b[j - 1];//如果存在其他木块，要将其他木块上移一位
		block[T].b[1] = T;//将木块x放回原位置
		postion[T] = T;
	}
	block[t].num -= cnt;//将目标木块x原本所在的堆减去所还原的数量
}//木块放回原位函数

void move(int a, int b) {
	int t, T;
	t = postion[a];	
	T = postion[b];
	block[T].num++;
	block[t].num--;
	block[T].b[block[T].num] = a;	
	postion[a] = postion[b];
}

void pile(int a, int b) {
	int pos, t, T, cnt = 0;	
	t = postion[a];	
	T = postion[b];
	for(int i = 1; i <= block[t].num; i++) 
		if (block[t].b[i] == a) {
			pos = i;	
			break;	
		}	
	for(int i = pos; i <= block[t].num; i++) {
		block[T].b[++block[T].num] = block[t].b[i];//移动到b的上面
		cnt++;
		postion[block[t].b[i]] = T;
	}
	block[t].num -= cnt;//减掉移动的木块数量
}
 
int main() {
	int n, a, b;
	char str[10], s[10];
	while (scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
			block[i].b[1] = i;	
			block[i].num = 1;
			postion[i] = i;
		}
		while (scanf("%s", str)) {
			if (!strcmp(str, "quit"))	
				break;	
			scanf("%d %s %d", &a, s, &b);	
			if (a == b || a >= n || b >= n || postion[a] == postion[b])
				continue;
			if (!strcmp(str, "move") && !strcmp(s, "onto")) {
				turn_back(a);	
				turn_back(b);
				move(a, b);
			}			
			else if (!strcmp(str, "move") && !strcmp(s, "over")) {
				turn_back(a);
				move(a, b);	
			}
			else if (!strcmp(str, "pile") && !strcmp(s, "onto")) {
				turn_back(b);	
				pile(a, b);
			}
			else if (!strcmp(str, "pile") && !strcmp(s, "over"))
				pile(a, b);
		}	
		for(int i = 0; i < n; i++) {
			printf("%d:", i);	
			for(int j = 1; j <= block[i].num; j++)	
				printf(" %d", block[i].b[j]);
			printf("\n");
		}
	}
	return 0;
}
