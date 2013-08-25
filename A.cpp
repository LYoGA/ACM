#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main() {
	int n, m, min = 999999999;
	int arr[1005];
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + m);
	for(int i = 0; (i + n - 1) < m; i++) {
		int d = arr[i + n - 1] - arr[i];
		if (min > d)
			min = d;	
	}
	printf("%d\n", min);
	return 0;

}
