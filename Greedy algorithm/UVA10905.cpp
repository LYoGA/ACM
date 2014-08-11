#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 55;

string s[MAXN];

int cmp(const string & a, const string & b) {
    return (a + b) > (b + a);
}

int main() {
    int n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++)
            cin >> s[i];
        sort(s, s + n, cmp); 
        for (int i = 0; i < n; i++) 
            cout << s[i];
        cout << endl;
    }
    return 0;
}
