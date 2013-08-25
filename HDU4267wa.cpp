#include<stdio.h>

int judge(long long x, long long y) {
	long long r;
	while (y != 0) {
		r = y;
		y = x % y;
		x = r;
	}
	if (x == 1)
		return 0;
	else
		return 1;
}

int main() {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		long long x, y, cnt = 0, num = 0;		
		long long i, j;	
		scanf("%lld %lld", &x, &y);	
		for(i = y; i >= x; i--) {
			cnt = 0;
			for(j = x; j <= i; j++)	{	
				if (i == j)
					continue;
				if (i % j != 0) {
					if (judge(i, j)){	
						printf("%lld %lld\n", i, j);
						cnt++;			
					}	
				}
			}
			if (cnt % 2 == 1) 
				num++;
		}
		printf("%lld\n", num);
	}
	return 0;
}
