/*思路：题目有点类似变形的约瑟夫环，不过感觉用链表做有些麻烦，所以用数组模拟
      刚开始每什么思路，后来在网上看到了一个很好的思路，就理解了一下，自己敲代码。
      是这样的，我们可以理解为在桌上有一堆扑克牌数量为n，按顺序放好，然后从左数k张，拿掉，同时从右数m张，拿掉。当从左数到尽头时，
      要再从最左边有牌的开始往右数，从右数的同左边数的方法一样。当桌上的牌拿光是结束。*/


#include<stdio.h>

int queue[25];

void init(int n) {
	for(int i = 1; i <= n; i++)
		queue[i] = i;
}

int main() {
	int n, k, m;
	while (scanf("%d %d %d", &n, &k, &m)) {
		if (!n && !k && !m)	
			break;	
		init(n);
		
		int cnt = 0, front = 0, near = n + 1;
		while (cnt < n) {
			int c1 = 0, c2 = 0;	
			while (1) {
				if (queue[front] != 0)	
					c1++;	
				if (front > n)
					front = 0;
				if (c1 == k) {
					printf("%3d", queue[front]);	
					cnt++;		
					break;
				}	
				front++;		
			}
			while (1) {
				if (queue[near] != 0)	
					c2++;	
				if (near < 1)
					near = n + 1;
				if (c2 == m) {
					if (queue[front] != queue[near]) { 
						printf("%3d", queue[near]);
						cnt++;
					}			
					break;
				}	
				near--;	
			}
			queue[front] = 0;
			queue[near]	= 0;
			if (cnt != n)
			printf(",");	
		}
		printf("\n");
	}	
	return 0;
}
