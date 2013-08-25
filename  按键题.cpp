#include<stdio.h> 
#include<string.h>  
#include<ctype.h>
#include<algorithm>
using namespace std;

int main() 
{ 
	char s[110]; 
	int cnt, flag; 
	int cas; 
	scanf("%d", &cas); 
	while(cas--) { 
		cnt = flag = 0; 
		scanf("%s", s); 
		int len = strlen(s); 
		for(int i = 0; i < len; ++i) { 
			if(isupper(s[i])) { 
				if(flag == 1) 
					cnt++; 
				else { 
					if(i == (len - 1)) { 
						cnt += 2; 
					}
					else if(isupper(s[i + 1])) { 
						cnt += 2; 
						flag = 1; 
					}
					else { 
						cnt += 2; 
					} 
				} 
			}
			else { 
				if(flag == 0) 
					cnt++; 
				else { 
					if(i == (len-1)) { 
						cnt += 2; 
						flag = 0; 
					}
					else if(islower(s[i + 1])) { 
						cnt += 2; 
						flag = 0; 
					}
					else {//大写字母按shift也可以变大写字母  
						cnt += 2; 
					} 
				} 
			} 
		} 
		if(flag) 
			cnt++; 
		printf("%d\n", cnt);
	} 
	return 0; 
} 
