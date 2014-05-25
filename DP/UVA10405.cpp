#include <iostream>  
#include <cstdio>
#include <cstring>
using namespace std;  
#define N 1005  

int dp[N][N];  
char str1[N], str2[N];  

int LCSL(int len1,int len2){  
    for(int i = 1; i <= len1; i++){  
        for(int j = 1; j <= len2; j++){  
            if (str1[i - 1] == str2[j - 1]){  
                dp[i][j] = dp[i - 1][j - 1] + 1;  
            }  
            else{  
                dp[i][j] = max(dp[i - 1][j] , dp[i][j-1]) ;   
            }  
        }
    }  
    return dp[len1][len2];  
}  

int main(){  
    while(gets(str1) != NULL){  
        gets(str2);
        memset(dp, 0, sizeof(dp));
        int len1 = strlen(str1);  
        int len2 = strlen(str2);  
        cout << LCSL(len1, len2) << endl;  
    }  
    return 0;  
}  

/*#include <iostream>
#include <cstdio>
#include <cstring> 
#define N 1005

using namespace std;

int d[N][N];
char s1[N], s2[N];

int dp(int l1, int l2) {
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) 
            if (s1[i - 1] == s2[j - 1]) 
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    }
    return d[l1][l2];
}

int main () {
    while (gets(s1) != NULL) {
        gets(s2); 
        memset(d, 0, sizeof(d));
        int l1 = strlen(s1); 
        int l2 = strlen(s2);
        cout << dp(l1, l2) << endl;
    }   
    return 0;
}*/

