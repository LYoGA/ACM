#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 250

char str[N][N];
int cnt;

void dfs(int x, int y) {
	int i, j;	
	for(i = y; str[x][i] == '-'; i++)
		if (str[x + 1][i] != ' ' && str[x + 1][i] != '\0') {
			printf("%c(", str[x + 1][i]);	
			if (x + 1 < cnt && str[x + 2][i] == '|') {
				for(j = i; j && str[x + 3][j - 1] == '-'; j--)	
					dfs(x + 3, j);	
			}		
			printf(")");
		}
}

int main() {
	int cas;
	scanf("%d", &cas);
	getchar();
	while (cas--) {
		cnt = 1;
		memset(str, 0, sizeof(str));
		while (gets(str[cnt]) != NULL) {
			if (!strcmp(str[cnt], "#"))	
				break;
			cnt++;
		}	
		if (cnt == 1)
			printf("()\n");
		else {
			int len = strlen(str[1]);	
			for(int i = 0; i < len; i++)
				str[0][i] = '-';
			printf("(");	
			dfs(0, 0);
			printf(")\n");
		}
	}
	return 0;
}
