#include<stdio.h>
#include<string.h>

int main() {
	int cas;
	scanf("%d", &cas);

	while (cas--) {
		int n, cnt = 0;
		char s[300][100], str[300][100];
		scanf("%d", &n);
		getchar();

		for(int i = 0; i < n; i++)	
			gets(s[i]);
		for(int i = 0; i < n; i++)
			gets(str[i]);

		int i = n - 1, j = n - 1;
		while (i >= 0 && j >= 0) {
				if (strcmp(s[i], str[j])) {			
					i--;	
				}	
				else {			
					i--;
					j--;
				}	
		}
		while (j >= 0)
			puts(str[j--]);	
		printf("\n");
	}

	return 0;
}
