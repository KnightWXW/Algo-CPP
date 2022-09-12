#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 279. 完全平方数

//      链接：https://leetcode.cn/problems/perfect-squares/

//      给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

//      完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

//      示例 1：
//      输入：n = 12
//      输出：3
//      解释：12 = 4 + 4 + 4

//      示例 2：
//      输入：n = 13
//      输出：2
//      解释：13 = 4 + 9

//      提示：
//          1 <= n <= 104

int generateRandomNum(int low, int high);
int numSquares_A(int n);
int dfsNumSquares_A(int n);
int numSquares_B(int n);
int dfsNumSquares_B(int n, vector<int> arr);
int numSquares_C(int n);

int main()
{
    int n = generateRandomNum(0, 60);
    printf("随机数字为：%d\n", n);
    printf("暴力递归：%d\n", numSquares_A(n));
    printf("记忆化搜索：%d\n", numSquares_B(n));
    printf("动态规划：%d\n", numSquares_C(n));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int numSquares_A(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return dfsNumSquares_A(n);
}

int dfsNumSquares_A(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX - 1;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, dfsNumSquares_A(n - (i * i)) + 1);
    }
    return ans;
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int numSquares_B(int n)
{
    if (n == 1)
    {
        return 1;
    }
    vector<int> arr(n + 1, 0);
    return dfsNumSquares_B(n, arr);
}

int dfsNumSquares_B(int n, vector<int> arr)
{
    if (n == 0)
    {
        return 0;
    }
    if (arr[n] > 0)
    {
        return arr[n];
    }
    int ans = INT_MAX - 1;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, dfsNumSquares_A(n - (i * i)) + 1);
        arr[n] = ans;
    }
    return ans;
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int numSquares_C(int n)
{
    if (n == 1)
    {
        return 1;
    }
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}