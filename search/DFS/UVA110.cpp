#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10;

char str[MAXN];
int n;

void space(int cnt) {
    for(int i = 0; i < cnt; i++)  
        printf("  ");  
}

void deal(int cur, vector<char> &s) {
    if (cur == n) {
        space(n);
        printf("writeln("); 
        printf("%c", s[0]);
        for (int i = 1; i < n; i++) 
            printf(",%c", s[i]);
        printf(")\n");
        return;
    }
    else {
        for (int i = cur; i >= 0; i--) {
            space(cur);
            if (i < cur) 
                printf("else ");
            if (i)
                printf("if %c < %c then", s[i - 1], cur + 'a');
            printf("\n"); 
            vector<char> ss(s); 
            ss.insert(ss.begin() + i, 'a' + cur);
            deal(cur + 1, ss);
        }  
    }  
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);     
        for (int i = 0; i < n; i++)
            str[i] = 'a' + i;
        printf("program sort(input,output);\nvar\n");
        printf("%c", str[0]);
        for (int i = 1; i < n; i++)
            printf(",%c", str[i]);
        printf(" : integer;\nbegin\n");
        printf("  readln(%c", str[0]);
        for (int i = 1; i < n; i++)
            printf(",%c", str[i]);
        printf(");\n");
        vector<char> s;
        s.push_back('a');
        deal(1, s);
        printf("end.\n");
        if (cas)
            printf("\n"); 
    }
    return 0;
}
