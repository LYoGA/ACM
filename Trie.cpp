typedef struct Trie{
	struct Trie *next[MAX];
	int v;
};

Trie *root;

void createTrie(char *str){
	int len = strlen(str);
	Trie *p = &root, *q;
	for(int i = 0;i < len; i++){
		int id = str[i] - 'a';	
		if (p -> next[id] == NULL){
			Trie *q = new Trie;	
			q -> = 1;//初始v==1
			for(int j = 0;j < MAX; j++)
				q -> next[j] = NULL;
			p -> next[id] = q;
			p = p -> next[id];	
		}
		else
		{
			p -> next[id] -> v++;	
			p = p -> next[id];	
		}
	}
	p -> v = -1;//若为结尾，则将v改成-1表示
}

int findTrie(char *str){
	int len = strlen(str);
	Trie *p = &root;
	for(int i = 0;i < len; i++){
		int id = str[i] - 'a';	
		p = p -> next[id];	
		if (p == NULL)	//若为空集，表示不存在以此为前缀的串
			return 0;	
		if (p -> v == -1)//字符集中已有此串的前缀
			return -1;
	}
	return -1;//此串是字符集中某串的前缀
}

int dealTrie(Trie * T){
	int i;
	if (T == NULL)
		return 0;
	for(int i = 0;i < MAX; i++){
		if (T -> next[i] != NULL)	
			deal(T -> next[i]);	
	}
	free(T);
	return 0;
}
