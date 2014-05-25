#include<stdio.h>  
#include<string.h>  
//n表示待查序列长度, s1是前序序列, s2是中序序列, s是ans数组的指针  
void build(int n, char *s1, char *s2, char *s) {  
	if(n <= 0)  
		return;  
	int p = strchr(s2, s1[0]) - s2; //根据前序, 在中序中找到根节点(可用上面给出的数据模拟, 假设第一个根节点是4)  
	build(p, s1+1, s2, s); //左儿子部分, 试着理解: 前序s1的第一个4找到后, 接下来的s1+1是左儿子部分的根结点(即2), p是左儿子的长度  
	build(n-1-p, s1+p+1, s2+p+1, s+p); //右儿子部分, 长度为n-p-1, 是总长度减左树再减根结点1个(即4), s1+p+1 and s2+p+1 同理  
	s[n-1] = s1[0]; //由于求后序遍历, 所以最后将开头得到的根结点, 放在答案数组的最后~  
}  

int main() {  
	char str1[30], str2[30];  
	char ans[30];  
	int len;  
	while(scanf("%s%s", str1, str2) != EOF) {  
		len = strlen(str1);  
		build(len, str1, str2, ans);  
		ans[len] = '\0';  
		puts(ans);  
	}  
	return 0;  
} 

#include<stdio.h>  
#include<string.h>  

int pos;  

void build(int n, char *s1, char *s2, char *s) {  
	if(n <= 0)  
		return ;  
	int p = strchr(s1, s2[n-1]) - s1; //找根  
	s[0] = s2[n-1]; //先保存根节点! 还是放在答案数组的开头! 体会和上面保存方式的不一样!  
	build(p, s1, s2, s+1); //左子树, 与上面同理, 但是在中序结构(左-根-右)和后序结构(左-右-根)中, 左树都是在开头, 于是s1 s2都从开头继续递归  
	build(n-p-1, s1+p+1, s2+p, s+p+1); //右子树, 根据中序结构, 在找到根后, s1要减去左树长度(p), 再减去根长度(1), 而后序s2只要减去左树长度  
}  

int main() {  
	char str1[50];  
	char str2[50];  
	while(scanf("%s%s", str1, str2) != EOF) {  
		char ch, ans[50];  
		int len = strlen(str1);  
		pos = 0;  
		build(len, str1, str2, ans);  
		ans[len] = '\0';  
		puts(ans);  
	}  
	return 0;  
}  
