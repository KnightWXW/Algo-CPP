#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      斐波那契数列：

//      斐波那契数（通常用 F(n) 表示）形成的序列称为 斐波那契数列。
//      该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
//      F(0) = 0，F(1) = 1;
//      F(n) = F(n - 1) + F(n - 2)，其中 n > 1;
//      给定n ，请计算 F(n) 。

int generateRandomNum(int low, int high);
int fibonacci_A(int n);
int fibonacci_B(int n);
int dfsFibonacci_B(int n, int *arr);
int fibonacci_C(int n);
int fibonacci_D(int n);
int fibonacci_E(int n);
vector<vector<int>> digitMatMul(vector<vector<int>> mat, int k);
vector<vector<int>> matMulMat(vector<vector<int>> mat1, vector<vector<int>> mat2);

int main()
{
    int num = generateRandomNum(0, 46);
    printf("随机数字为：%d\n", num);
    printf("暴力递归：%d\n", fibonacci_A(num));
    printf("记忆化搜索：%d\n", fibonacci_B(num));
    printf("动态规划：%d\n", fibonacci_C(num));
    printf("动态规划（空间优化）：%d\n", fibonacci_D(num));
    printf("矩阵快速幂：%d\n", fibonacci_E(num));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int fibonacci_A(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci_A(n - 1) + fibonacci_A(n - 2);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int fibonacci_B(int n)
{
    int *arr;
    arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }
    int ans = dfsFibonacci_B(n, arr);
    free(arr);
    return ans;
}

int dfsFibonacci_B(int n, int *arr)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (arr[n] > 0)
    {
        return arr[n];
    }
    int tem = dfsFibonacci_B(n - 1, arr) + dfsFibonacci_B(n - 2, arr);
    arr[n] = tem;
    return arr[n];
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int fibonacci_C(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int *dp;
    dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

// 动态规划（空间优化）：
// Time: O(N)
// Space: O(1)
int fibonacci_D(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 矩阵快速幂
// Time: O(logN)
// Space: O(1)
int fibonacci_E(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    vector<vector<int>> base = {{1,1},
                                {1,0}};
    vector<vector<int>> ans = digitMatMul(base, n - 2);
    return ans[0][0] + ans[1][0];
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
        k >>= 1;
        tem = matMulMat(tem, tem);
    }
    return ans;
}

vector<vector<int>> matMulMat(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    int row1 = mat1.size(), col1 = mat1[0].size();
    int row2 = mat2.size(), col2 = mat2[0].size();
    vector<vector<int>> mul(row1, vector<int>(col2, 0));
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            for (int k = 0; k < row2; k++)
            {
                mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return mul;
}