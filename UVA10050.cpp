#include<stdio.h>
#include<string.h>

int main() {
	int cas;
	int arr[105], vis[3700];
	scanf("%d", &cas);
	while (cas--) {
		int n, p, cnt = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &p);
		for(int i = 0; i < p; i++)
			scanf("%d", &arr[i]);	
		for(int i = 0; i < p; i++) {
			for(int j = 0; j <= n; j += arr[i]) {
				if (j != 6 && j % 7 != 6 && j % 7 != 0)			
					vis[j] = 1;	
			}
		}
		for(int i = 0; i <= n; i++)
			if (vis[i])
				cnt++;
		printf("%d\n", cnt);
	}	
	return 0;
}
