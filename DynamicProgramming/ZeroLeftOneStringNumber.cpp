#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      给定一个数 n，想象只由 ‘0’ 和 ‘1’ 两种字符，
//      组成的所有长度为 n 的字符串。
//      如果某个字符串，任何 ‘0’ 字符的左边都有 ‘1’ 紧挨着，认为这个字符串达标。
//      返回有多少达标的字符串。

//      示例 1:
//          输入: n == 1
//          输出: 1
//              说明：0(×), 1(√)

//      示例 2:
//          输入: n == 2
//          输出: 2
//              说明：00(×), 01(√), 10(×), 11(√),

//      示例 3:
//          输入: n == 3
//          输出: 3
//              说明：000(×), 001(×), 010(×), 011(×),
//                   100(×), 101(√), 110(√), 111(√),

int generateRandomNum(int low, int high);
int zeroLeftOneStringNumber_A(int n);
int dfsZeroLeftOneStringNumber_A(int i, int n);
int zeroLeftOneStringNumber_B(int n);
int dfsZeroLeftOneStringNumber_B(int i, int n, int *arr);
int zeroLeftOneStringNumber_C(int n);
int zeroLeftOneStringNumber_D(int n);
int zeroLeftOneStringNumber_E(int n);
vector<vector<int>> digitMatMul(vector<vector<int>> mat, int k);
vector<vector<int>> matMulMat(vector<vector<int>> mat1, vector<vector<int>> mat2);

int main()
{
    int n = generateRandomNum(0, 10);
    printf("随机数字为：%d\n", n);
    printf("暴力递归：%d\n", zeroLeftOneStringNumber_A(n));
    printf("记忆化搜索：%d\n", zeroLeftOneStringNumber_B(n));
    printf("动态规划：%d\n", zeroLeftOneStringNumber_C(n));
    printf("动态规划（空间优化）：%d\n", zeroLeftOneStringNumber_D(n));
    printf("矩阵快速幂：%d\n", zeroLeftOneStringNumber_E(n));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int zeroLeftOneStringNumber_A(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return dfsZeroLeftOneStringNumber_A(1, n);
}

// 函数意义：
//      n: 字符的总个数
//      i: 字符的开始索引位置：
// 默认 第 i - 1 位置 字符 为 ‘1’，
//      如果 第 i - 1 位置 为 ‘0’，所有选择均不合适。
// 如果 第 i 位置 字符 为 ‘1’, 接下来 选择 为 f(i + 1, n) ;
// 如果 第 i 位置 字符 为 ‘0’, 第 i + 1 位置 字符 为 ‘1’, 接下来 选择 为 f(i + 2, n)；
int dfsZeroLeftOneStringNumber_A(int i, int n)
{
    if (i == n - 1)
    {
        return 2;
    }
    if (i == n)
    {
        return 1;
    }
    return dfsZeroLeftOneStringNumber_A(i + 1, n) + dfsZeroLeftOneStringNumber_A(i + 2, n);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int zeroLeftOneStringNumber_B(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int *arr;
    arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }

    int ans = dfsZeroLeftOneStringNumber_B(1, n, arr);

    free(arr);
    return ans;
}

int dfsZeroLeftOneStringNumber_B(int i, int n, int *arr)
{
    if (i == n - 1)
    {
        arr[n - 1] = 2;
        return 2;
    }
    if (i == n)
    {
        arr[n] = 1;
        return 1;
    }
    if (arr[i] > 0)
    {
        return arr[i];
    }
    int p1 = dfsZeroLeftOneStringNumber_B(i + 1, n, arr);
    int p2 = dfsZeroLeftOneStringNumber_B(i + 2, n, arr);
    arr[i] = p1 + p2;
    return p1 + p2;
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int zeroLeftOneStringNumber_C(int n)
{
    if (n == 0)
    {
        return 0;
    }
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

// 动态规划（空间优化）：
// Time: O(N)
// Space: O(1)
int zeroLeftOneStringNumber_D(int n)
{
    if (n == 0)
    {
        return 0;
    }
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

// 矩阵快速幂
// Time: O(logN)
// Space: O(1)
int zeroLeftOneStringNumber_E(int n){
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    vector<vector<int>> base = {{1,1},
                                {1,0}};
    vector<vector<int>> tem = digitMatMul(base, n - 2);
    vector<vector<int>> ori = {{2,1}};
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
    vector<vector<int>> mul(row1, vector<int>(col2, 0));
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < row2; k++)
            {
                mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return mul;
}