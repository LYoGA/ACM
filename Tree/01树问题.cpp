#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

typedef struct Trie{
	int v;
	Trie *next[2];
}Trie;

Trie *root;

void createTrie(char *s){
	Trie *p = root, *q;
	int len = strlen(s);
	for(int i = 0;i < len; i++){
		int id = s[i] - '0';		
		if (p -> next[id] == NULL){
			Trie *q = new Trie;	
			q -> v = 1;
			for(int j = 0;j < 2; j++)	
				q -> next[j] = NULL; 
			p -> next[id] = q; 	
			p = p -> next[id];	
		}		
	}
	p -> v = -1;
}

int findTrie(char *s){
	Trie *p = root;
	int len = strlen(s);
	for(int i = 0;i < len; i++){
		int id = s[i] - '0';	
		p = p -> next[id];	
		if (p == NULL)
			return 0;
		if (p -> v == -1)	
			return -1;
	}
	return -1;
}

void  deal(Trie *T){	
	for(int i = 0;i < 2; i++){
		if(T -> next[i] != NULL)	
		deal(T -> next[i]);	
	}
	delete(T);	
}

int main(){
	char s[10]; 	
	int flag = 0, t = 0;	
	root = new Trie;	
	for(int i = 0;i < 2; i++)	
		root -> next[i] = NULL;
	while (scanf("%s", s) != EOF){		
		if (strcmp(s, "9") == 0){			
			if (flag) 	
				printf("Set %d is not immediately decodable\n", ++t);	
			else
				printf("Set %d is immediately decodable\n", ++t);	
			deal(root);		
			flag = 0;	
			root = new Trie;	
			for(int i = 0;i < 2; i++)	
				root -> next[i] = NULL;
			}	
		else{
			if (findTrie(s))	
				flag = 1;	
			if(flag)	
				continue;	
			createTrie(s);	
		}		
						
	}
	return 0;
}
