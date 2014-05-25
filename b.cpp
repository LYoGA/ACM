#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char s[5005 * 205][205];

int compare(const void *a, const void *b){

	return strcmp((char *)a, (char *)b);
}

int main(){
	int i = 0, j = 0;	
	char ch;
	while ((ch = getchar()) != EOF){
		if (isalpha(ch)) s[i][j++] = tolower(ch);	
		if (!isalpha(ch) && isalpha(s[i][0])){
			s[i++][j] = '\0';	
			j = 0;		
		}							
	}		
	qsort(s, i, sizeof(char)*205, compare);	
	for(j = 1, puts(s[0]);j < i; j++)	
		if(strcmp(s[j - 1], s[j]))	
			puts(s[j]);	
	
	return 0;
}
