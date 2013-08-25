#include<stdio.h>
#include<string.h>
#define MaxInt 0x3f3f3f3f
#define N 110

int map[N][N], low[N], vis[N];
int n;

int prim(){
	int pos, min, result = 0;
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	pos = 1;
	for(int i = 1;i <= n; i++)
		if (i != pos)
			low[i] = map[pos][i];
	for(int i = 1;i <= n; i++){
		min = MaxInt;
		for(int j = 1;j <= n; j++)
			if (!vis[j] && low[i] > map[pos][j]){
				min = low[j];	
				pos = j;	
			}	
		result += min;
		vis[pos] = 1;
		for(int j = 1;j <= n; j++)	
			if(!vis[j] && low[j] > map[pos][j])
				low[j] = map[pos][j];	
	}
	return result;	
}

int main(){
	int v,ans;
	while (scanf("%d", &n) != EOF){
			memset(map, MaxInt, sizeof(map));	
			for(int i = 1;i <= n; i++)
				for(int j = 1;j <= n; j++){
					scanf("%d", &v);	
					map[i][j] = map[j][i] = v;		
				}
				ans = prim();	
				printf("%d\n", ans);	
	}
	return 0;
}


