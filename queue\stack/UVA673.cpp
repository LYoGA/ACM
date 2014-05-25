#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	int n;
	char s[150];
	scanf("%d", &n);
	getchar();
	while (n--) {	
		stack <char> str;
		gets(s);	
		for(int i = 0; i < strlen(s); i++) {
			if (s[i] == '(' || s[i] == '[')	
				str.push(s[i]);	
			else if (s[i] == ')' || s[i] == ']') {	
				if (s[i] == ')' && !str.empty()) {
					if (str.top() == '(')
						str.pop();
				}
				else if (!str.empty() && s[i] == ']') {	
					if (str.top() == '[')
						str.pop();
				}	
				else 
					str.push(s[i]);
			}
		}
		if (str.empty())
			printf("Yes\n");
		else 
			printf("No\n");
			
	}
	return 0;
}
