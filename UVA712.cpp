#include<stdio.h> 
#include<string.h>
#include<math.h>

int main() {
	int n, m, t = 0;
	char s[100], str[150], temp[20];
	int arr[150], answer[150];

	while (scanf("%d", &n) != EOF && n) {
		getchar();	
		gets(s);
		scanf("%s", str);
		int p = pow(2, n);
		for(int i = p, j = 0; i < 2 * p, j < p; i++, j++)	
			arr[i] = str[j] - '0';

		scanf("%d", &m);
		getchar();
		int l, cnt = 0;
		for(int i = 0; i < m; i++) {
			int k = 1;
			gets(temp);	
			l = strlen(temp);	
			for(int j = 0; j < l; j++) {
				if (temp[j] - '0' == 0)	
					k = k * 2;	
				else
					k = k * 2 + 1;
			}
			answer[cnt++] = arr[k];
		}

		printf("S-Tree #%d:\n", ++t);
		for(int i = 0; i < m; i++)
			printf("%d", answer[i]);	
		printf("\n\n");
	}
	return 0;
}
