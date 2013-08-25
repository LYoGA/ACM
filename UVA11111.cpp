#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 1000000

int arr[N], stack[N], sum[N];

int deal(int *a, int n) {
	int top = 0;
	memset(stack, 0, sizeof(stack));
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n; i++){
		if(a[i] < 0) {  
			sum[top] -= a[i];//记录每一层的容量 
			stack[++top] = a[i];  
		}  
		else {  
			if(-stack[top] != a[i])//判断正数是否与栈顶的元素和为0
				return 0;   
			if(sum[top] >= a[i])//每一个进行判断的正数，要求要比下一层的容量大
				return 0;  
			stack[top] = 0;//元素出栈
			sum[top--] = 0;//当元素出栈时，其相应的容量要清零
		}
	}
	return 1;	
}

int main() {
	int cnt = 0;
	char ch;
	while (scanf("%d", &arr[cnt++]) != EOF) {
		int flag = 0;
		ch = getchar();		
		if (ch == '\n') {
			if (cnt % 2 == 1)
				flag = 0;
			else	
				flag = deal(arr, cnt);	
			if (flag)			
				printf(":-) Matrioshka!\n");
			else
				printf(":-( Try again.\n");
			cnt = 0;
		}
	}
	return 0;
}
