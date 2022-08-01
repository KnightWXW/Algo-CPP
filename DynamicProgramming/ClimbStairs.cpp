#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 70. 爬楼梯

//      链接：https://leetcode.cn/problems/climbing-stairs/

//      假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//      每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

//      示例 1：
//      输入：n = 2
//      输出：2
//      解释：有两种方法可以爬到楼顶。
//          1. 1 阶 + 1 阶
//          2. 2 阶

//      示例 2：
//      输入：n = 3
//      输出：3
//      解释：有三种方法可以爬到楼顶。
//          1. 1 阶 + 1 阶 + 1 阶
//          2. 1 阶 + 2 阶
//          3. 2 阶 + 1 阶

//      提示：1 <= n <= 45

int generateRandomNum(int low, int high);
int climbStairs_A(int n);
int climbStairs_B(int n);
int dfsClimbStairs_B(int n, int *arr);
int climbStairs_C(int n);
int climbStairs_D(int n);
int climbStairs_E(int n);
vector<vector<int>> digitMatMul(vector<vector<int>> mat, int k);
vector<vector<int>> matMulMat(vector<vector<int>> mat1, vector<vector<int>> mat2);

int main()
{
    int num = generateRandomNum(1, 47);
    printf("（暴力递归）：爬 %d 层楼梯的方法数为 %d\n", num, climbStairs_A(num));
    printf("（记忆化搜索）：爬 %d 层楼梯的方法数为 %d\n", num, climbStairs_B(num));
    printf("（动态规划）：爬 %d 层楼梯的方法数为 %d\n", num, climbStairs_C(num));
    printf("（动态规划-压缩空间）：爬 %d 层楼梯的方法数为 %d\n", num, climbStairs_D(num));
    printf("（矩阵快速幂）：爬 %d 层楼梯的方法数为 %d\n", num, climbStairs_E(num));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 暴力递归:
// Time: O(2^N)
// Space: O(N)
int climbStairs_A(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    int p1 = climbStairs_A(n - 1);
    int p2 = climbStairs_A(n - 2);

    return p1 + p2;
}

// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)
int climbStairs_B(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    int *arr;
    arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }

    int ans = dfsClimbStairs_B(n, arr);

    free(arr);
    return ans;
}

int dfsClimbStairs_B(int n, int *arr)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    if (arr[n] != 0)
    {
        return arr[n];
    }

    int p1 = dfsClimbStairs_B(n - 1, arr);
    int p2 = dfsClimbStairs_B(n - 2, arr);

    arr[n] = p1 + p2;
    return p1 + p2;
}

// 动态规划:
// Time: O(N)
// Space: O(N)
int climbStairs_C(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    return dp[n];
}

// 动态规划(压缩空间):
// Time: O(N)
// Space: O(1)
int climbStairs_D(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    int a = 1, b = 2;
    for (int i = 3; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 矩阵快速幂:
// Time: O(logN)
// Space: O(1)
int climbStairs_E(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    vector<vector<int>> base = {{1, 1},
                                {1, 0}};
    vector<vector<int>> ori = {{2, 1}};                            
    vector<vector<int>> tem = digitMatMul(base, n - 2);
    vector<vector<int>> ans = matMulMat(ori, tem);
    return ans[0][0];
}

vector<vector<int>> digitMatMul(vector<vector<int>> mat, int k)
{
    int row = mat.size(), col = mat[0].size();
    vector<vector<int>> ans(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        ans[i][i] = 1;
    }
    vector<vector<int>> tem = mat;
    while (k != 0)
    {
        if ((k & 1) == 1)
        {
            ans = matMulMat(ans, tem);
        }
        tem = matMulMat(tem, tem);
        k >>= 1;
    }
    return ans;
}

vector<vector<int>> matMulMat(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    int row1 = mat1.size(), col1 = mat1[0].size();
    int row2 = mat2.size(), col2 = mat2[0].size();
    vector<vector<int>> ans(row1, vector<int>(col2, 0));
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < row2; k++)
            {
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return ans;
}