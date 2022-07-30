#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/*
    假设有排成一行的 n 个位置，记为 1~n ,n>=2
    开始时机器人在其中的 cur 位置上(M一定是 1~N 中的一个)
    如果机器人来到 1 位置，那么下一步只能往右来到 2 位置;
    如果机器人来到 n 位置，那么下一步只能往左来到 n-1 位置;
    如果机器人来到中间位置，那么下一步可以往左走或者往右走;
    规定机器人必须走 cnt 步，最终能来到 end 位置(P 也是 1-n 中的一个)的方法有多少种
    给定四个参数 n、cur、cnt、end，返回方法数.
*/

int robotWalking_A(int n, int cur, int cnt, int end);
int robotWalking_B(int n, int cur, int cnt, int end);
int dfsRobotWalking_B(int n, int cur, int cnt, int end, int **arr);
int robotWalking_C(int n, int cur, int cnt, int end);
int robotWalking_D(int n, int cur, int cnt, int end);

int main()
{
    int n = 5;
    int cur = 2;
    int cnt = 6;
    int end = 4;
    printf("暴力递归：%d\n", robotWalking_A(n, cur, cnt, end));               // 13
    printf("记忆化搜索：%d\n", robotWalking_B(n, cur, cnt, end));             // 13
    printf("动态规划：%d\n", robotWalking_C(n, cur, cnt, end));               // 13
    printf("动态规划（空间优化）：%d\n", robotWalking_C(n, cur, cnt, end));    // 13
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int robotWalking_A(int n, int cur, int cnt, int end)
{
    if (cur <= 0 || cur > n || end <= 0 || end > n || cnt < 0 || n <= 0)
    {
        return -1;
    }
    if (cnt == 0)
    {
        if (cur == end)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (cur == 1)
    {
        return robotWalking_A(n, cur + 1, cnt - 1, end);
    }
    else if (cur == n)
    {
        return robotWalking_A(n, cur - 1, cnt - 1, end);
    }
    else
    {
        return robotWalking_A(n, cur + 1, cnt - 1, end) + robotWalking_A(n, cur - 1, cnt - 1, end);
    }
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int robotWalking_B(int n, int cur, int cnt, int end)
{
    if (cur <= 0 || cur > n || end <= 0 || end > n || cnt < 0 || n <= 0)
    {
        return -1;
    }

    int **arr;
    arr = new int*[cnt + 1];
    for (int i = 0; i < cnt + 1; i++){
        arr[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++){
            arr[i][j] = 0;
        }
    }

    int ans = dfsRobotWalking_B(n, cur, cnt, end, arr);

    for (int i = 0 ; i < cnt + 1 ; i++){
        free(arr[i]);
    }
    free(arr);

    return ans;
}

int dfsRobotWalking_B(int n, int cur, int cnt, int end, int **arr)
{
    if (arr[cnt][cur] != 0)
    {
        return arr[cnt][cur];
    }
    int steps = 0;
    if (cnt == 0)
    {
        if (cur == end)
        {
            steps = 1;
        }
        else
        {
            steps = 0;
        }
    }
    else if (cur == 1)
    {
        steps = dfsRobotWalking_B(n, cur + 1, cnt - 1, end, arr);
    }
    else if (cur == n)
    {
        steps = dfsRobotWalking_B(n, cur - 1, cnt - 1, end, arr);
    }
    else
    {
        steps = dfsRobotWalking_B(n, cur + 1, cnt - 1, end, arr) + dfsRobotWalking_B(n, cur - 1, cnt - 1, end, arr);
    }
    arr[cnt][cur] = steps;
    return steps;
}

// 动态规划：
// Time: O(cnt * n)
// Space: O(cnt * n)
int robotWalking_C(int n, int cur, int cnt, int end)
{
    if (cur <= 0 || cur > n || end <= 0 || end > n || cnt < 0 || n <= 0)
    {
        return -1;
    }

    int **dp;
    dp = new int*[cnt + 1];
    for (int i = 0; i < cnt + 1; i++){
        dp[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++){
            dp[i][j] = 0;
        }
    }
    
    dp[0][end] = 1;
    for (int i = 1; i <= cnt; i++)
    {
        dp[i][1] = dp[i - 1][2];
        for (int j = 1; j <= n - 1; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
        dp[i][n] = dp[i - 1][n - 1];
    }

    int ans = dp[cnt][cur];

    for (int i = 0 ; i < cnt + 1 ; i++){
        free(dp[i]);
    }
    free(dp);

    return ans;
}

// 动态规划(空间优化)：
// Time: O(n)
// Space: O(n)
int robotWalking_D(int n, int cur, int cnt, int end)
{
    if (cur <= 0 || cur > n || end <= 0 || end > n || cnt < 0 || n <= 0)
    {
        return -1;
    }

    int *dp;
    dp = new int[n + 1];
    for (int i = 0; i < n + 1; i++){
        dp[i] = 0;
    }
    
    dp[end] = 1;
    for (int i = 1; i <= cnt; i++)
    {
        dp[1] = dp[2];
        for (int j = 1; j <= n - 1; j++)
        {
            dp[j] = dp[j - 1] + dp[j + 1];
        }
        dp[n] = dp[n - 1];
    }

    int ans = dp[cur];

    free(dp);

    return ans;
}

