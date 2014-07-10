#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
	char str[200];
	while (gets(str) != NULL) {		
		printf("Expression: ");		
		puts(str);
		char s[200];
		memset(s, 0, sizeof(s));	
		int num1[26], num2[26], vis[26];	
		int cnt = 0;	
		for(int i = 0;i < strlen(str); i++)
			if (str[i] == '+' || str[i] == '-' || isalpha(str[i]))	
				s[cnt++] = str[i];	
		for(int i = 0;i < 26; i++) {
			num1[i] = i + 1;	
			num2[i] = i + 1;	
			vis[i] = 0;	
		}	
		for(int i = 0;i < cnt; i++) {
			if (isalpha(s[i]))	
				vis[s[i] - 'a'] = 1;	
			if (s[i] == '+' && s[i + 1] == '+' && isalpha(s[i + 2])) {
				vis[s[i + 2] - 'a'] = 1;				
				num1[s[i + 2] - 'a']++;	
				num2[s[i + 2] - 'a']++;	
				s[i] = '#';	
				s[i + 1] = '#';		
			}	
			if (s[i] == '-' && s[i + 1] == '-' && isalpha(s[i + 2])) {
				vis[s[i + 2] - 'a'] = 1;	
				num1[s[i + 2] - 'a']--;	
				num2[s[i + 2] - 'a']--;	
				s[i] = '#';
				s[i + 1] = '#';	
			}
			if (isalpha(s[i]) && s[i + 1] == '+' && s[i + 2] == '+') {
				vis[s[i] - 'a'] = 1;
				num1[s[i] - 'a']++;	
				s[i + 1] = '#';	
				s[i + 2] = '#'; 	
			}
			if (isalpha(s[i]) && s[i + 1] == '-' && s[i + 2] == '-') {
				vis[s[i] - 'a'] = 1;	
				num1[s[i] - 'a']--;	
				s[i + 1] = '#';
				s[i + 2] = '#';	
			}		
		}	

		int flag = 1, sum = 0;

		for(int i = 0;i < cnt ; i++) {
			if (isalpha(s[i]) && flag) {
				sum += num2[s[i] - 'a'];				
				flag = 0;		
			}	
			else if (s[i] == '+' || s[i] == '-') {
				if (s[i] == '+') {
					for(int j = i; ; j++)	
						if (isalpha(s[j])) {	
							sum += num2[s[j] - 'a'];		
							break;		
						}	
				}	
				if (s[i] == '-') {
					for(int j = i; ; j++)	
						if (isalpha(s[j])) {	
							sum -= num2[s[j] - 'a'];		
							break;	
						}	
				}	
			}	
		}	

		printf("    value = %d\n", sum);		
		for(int i = 0;i < 26; i++) {
			if (vis[i]) {
				printf("    %c = %d\n", i + 'a', num1[i]);		
			}	
		}	
	}	
	return 0;
}
