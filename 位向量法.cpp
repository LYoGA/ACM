#include<stdio.h>

void print_subset(int n, int *b, int cur)
{
	if(cur == n)
	{
		for(int i = 0; i < cur; i++)	
			if(b[i])	
				printf("%d", i);	
		printf("\n");	
		return;	
	}
	b[cur] = 1;
	print_subset(n, b, cur + 1);
	b[cur] = 0;
	print_subset(n, b, cur + 1);
}

int main(){

	int n;
	int b[100];	
	scanf("%d", &n);
	while(n)	
		print_subset(n, b, 0);	
	return 0;
}














