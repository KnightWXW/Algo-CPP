#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      剑指 Offer II 098. 路径的数目

//      链接：https://leetcode.cn/problems/2AoeFn

//      一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//      机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//      问总共有多少条不同的路径？

int generateRandomNum(int low, int high);
int uniquePaths_A(int m, int n);
int dfsUniquePaths_A(int m, int n, int i, int j);
int uniquePaths_B(int m, int n);
int dfsUniquePaths_B(int m, int n, int i, int j, int **arr);
int uniquePaths_C(int m, int n);
int uniquePaths_D(int m, int n);

int main()
{
    int m = generateRandomNum(1, 17);
    int n = generateRandomNum(1, 17);
    printf("m, n：%d %d\n", m, n);
    printf("暴力递归：%d\n", uniquePaths_A(m, n));
    printf("记忆化搜索：%d\n", uniquePaths_B(m, n));
    printf("动态规划：%d\n", uniquePaths_C(m, n));
    printf("动态规划(空间优化)：%d\n", uniquePaths_D(m, n));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int uniquePaths_A(int m, int n)
{
    if (m <= 0 || n <= 0)
    {
        return 0;
    }
    return dfsUniquePaths_A(m, n, 1, 1);
}

int dfsUniquePaths_A(int m, int n, int i, int j)
{
    if (i <= 0 || j <= 0 || i > m || j > n)
    {
        return 0;
    }
    if (i == m && j == n)
    {
        return 1;
    }
    return dfsUniquePaths_A(m, n, i + 1, j) + dfsUniquePaths_A(m, n, i, j + 1);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int uniquePaths_B(int m, int n)
{
    if (m <= 0 || n <= 0)
    {
        return 0;
    }
    int **arr;
    arr = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        arr[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            arr[i][j] = 0;
        }
    }

    int ans = dfsUniquePaths_B(m, n, 1, 1, arr);

    for (int i = 0; i < m + 1; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return ans;
}

int dfsUniquePaths_B(int m, int n, int i, int j, int **arr)
{
    if (i <= 0 || j <= 0 || i > m || j > n)
    {
        return 0;
    }
    if (arr[i][j] > 0)
    {
        return arr[i][j];
    }
    if (i == m && j == n)
    {
        arr[m][n] = 1;
        return 1;
    }
    return dfsUniquePaths_B(m, n, i + 1, j, arr) + dfsUniquePaths_B(m, n, i, j + 1, arr);
}

// 动态规划：
// Time: O(m * n)
// Space: O(m * n)
int uniquePaths_C(int m, int n)
{
    if (m <= 0 || n <= 0)
    {
        return 0;
    }

    int **dp;
    dp = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        dp[i][n] = 1;
    }
    for (int j = 1; j <= n; j++)
    {
        dp[m][j] = 1;
    }

    for (int i = m - 1; i >= 1; i--)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
        }
    }

    int ans = dp[1][1];

    for (int i = 0; i < m + 1; i++)
    {
        free(dp[i]);
    }

    free(dp);

    return ans;
}

// 动态规划(空间优化)：
// Time: O(m * n)
// Space: O(n)
int uniquePaths_D(int m, int n)
{
    if (m <= 0 || n <= 0)
    {
        return 0;
    }

    int *dp;
    dp = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = 1;
    }

    for (int i = m - 1; i >= 1; i--)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            dp[j] += dp[j + 1];
        }
    }

    int ans = dp[1];

    free(dp);

    return ans;
}