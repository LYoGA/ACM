#include<stdio.h>

int flag;

int dfs() {
	int wl, dl, wr, dr;
	scanf("%d %d %d %d", &wl, &dl, &wr, &dr);
	if (wl == 0)
		wl = dfs();
	if (wr == 0)
		wr = dfs();
	if (wl * dl == wr * dr) 
		return wl + wr;	
	else
		return flag = 0;	
}

int main() {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		flag = 1;
		dfs();	
		if (flag)	
			printf("YES\n");
		else
			printf("NO\n");
		if (cas)	
			printf("\n");	
	}
	return 0;
}
