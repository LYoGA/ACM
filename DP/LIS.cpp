//最长上升子序列
//O(n * n)
int LIS() {
    int Max = 1;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i] = 1; 
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1); 
        if (Max < dp[i])
            Max = dp[i];
    }
    return Max;
}


//O(N*log(N))
//二分搜索降低时间复杂度(手写二分查找)
int search(int n, int num) {
    int l = 1, r = n; 
    while (l <= r) {
        int mid = (l + r) / 2; 
        if (num > c[mid] && num <= c[mid + 1]) 
            return mid + 1;
        else if (num <= c[mid])
            r = mid - 1;
        else 
            l = mid + 1; 
    } 
}

void LIS() {
    int size = 1, temp, Max = 0; 
    c[1] = a[1];
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] <= c[1]) 
            temp = 1;
        else if (a[i] > c[size])
            temp = ++size;
        else
            temp = search(size, a[i]); 
        c[temp] = a[i]; 
        dp[i] = temp;
        if (dp[i] > Max)
            Max = d[i];
    } 
}


//O(N*log(N))
//二分搜索降低时间复杂度(函数二分查找)
void LIS() {
    for (int i = 1; i <= n; i++)
        g[i] = INF;
    for (int i = 0; i < n; i++) {
        int k = lower_bound(g + 1, g + n + 1, arr[i]) - g; 
        d[i] = k; 
        g[k] = arr[i]; 
        ans = max(ans, d[i]);
    } 
}





