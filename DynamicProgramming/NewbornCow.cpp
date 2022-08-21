#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      奶牛生小牛问题
//      某农场有一头成熟的母牛，往后的每年：
//           1）每一只成熟的母牛都会生一只母牛
//           2）每一只新出生的母牛都在出生的第三年成熟
//           3）每一只母牛永远不会死
//      请问 n 年后，此农场一共有多少头牛？

int generateRandomNum(int low, int high);
int newbornCow_A(int n);
int newbornCow_B(int n);
int dfsNewbornCow_B(int n, int *arr);
int newbornCow_C(int n);
int newbornCow_D(int n);
int newbornCow_E(int n);
vector<vector<int>> digitMatMul(vector<vector<int>> mat, int k);
vector<vector<int>> matMulMat(vector<vector<int>> mat1, vector<vector<int>> mat2);

int main()
{
    int n = generateRandomNum(0, 56);
    printf("（暴力递归）： 在 %d 年后，此农场共有多少 %d 头牛\n", n, newbornCow_A(n));
    printf("（记忆化搜索）：在 %d 年后，此农场共有多少 %d 头牛\n", n, newbornCow_B(n));
    printf("（动态规划）：在 %d 年后，此农场共有多少 %d 头牛\n", n, newbornCow_C(n));
    printf("（动态规划-压缩空间）：在 %d 年后，此农场共有多少 %d 头牛\n", n, newbornCow_D(n));
    printf("（矩阵快速幂）：在 %d 年后，此农场共有多少 %d 头牛\n", n, newbornCow_E(n));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 暴力递归:
// Time: O(2^N)
// Space: O(N)
int newbornCow_A(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 3;
    }
    // 上一年存活下来的奶牛数量：
    int p1 = newbornCow_A(n - 1);
    // 三年前有的奶牛数量现在已经成熟，可以生小牛：
    int p2 = newbornCow_A(n - 3);
    return p1 + p2;
}

// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)
int newbornCow_B(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 3;
    }
    int *arr;
    arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }

    int ans = dfsNewbornCow_B(n, arr);

    free(arr);
    return ans;
}

int dfsNewbornCow_B(int n, int *arr)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 3;
    }
    if (arr[n] != 0)
    {
        return arr[n];
    }

    int p1 = dfsNewbornCow_B(n - 1, arr);
    int p2 = dfsNewbornCow_B(n - 3, arr);

    arr[n] = p1 + p2;
    return p1 + p2;
}

// 动态规划:
// Time: O(N)
// Space: O(N)
int newbornCow_C(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 3;
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 1];
    }

    return dp[n];
}

// 动态规划(压缩空间):
// Time: O(N)
// Space: O(1)
int newbornCow_D(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 3;
    }
    int a = 1, b = 2, c = 3;
    for (int i = 4; i <= n; i++)
    {
        int d = a + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

// 矩阵快速幂:
// Time: O(logN)
// Space: O(1)
int newbornCow_E(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 3;
    }
    vector<vector<int>> base = {{1, 1, 0},
                                {0, 0, 1},
                                {1, 0, 0}};
    vector<vector<int>> ori = {{3,2,1}};
    vector<vector<int>> tem = digitMatMul(base, n - 3);
    vector<vector<int>> ans = matMulMat(ori, tem);
    return  ans[0][0];
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