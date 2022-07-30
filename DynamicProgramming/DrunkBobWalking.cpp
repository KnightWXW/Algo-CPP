#include <stdio.h>
#include <math.h>

using namespace std;

//      给定 五 个参数，n，m，row，col，k。
//      表示在 n × m 的区域上，醉汉Bob 初始在 (row,col) 位置。
//      Bob一共要迈出k步，且每步都会等概率向上下左右四个方向走一个单位。
//      任何时候Bob只要离开 n × m的区域，就直接死亡。
//      返回 k步 之后，Bob 还在 n × m 的区域的概率。

double drunkBobWalking_A(int n, int m, int ow, int col, int k);
double dfsDrunkBobWalking_A(int n, int m, int row, int col, int k);
double drunkBobWalking_B(int n, int m, int ow, int col, int k);
double dfsDrunkBobWalking_B(int n, int m, int row, int col, int k, double ***arr);
double drunkBobWalking_C(int n, int m, int row, int col, int k);
double pickElementFromArr(double ***arr, int i, int j, int cnt, int n, int m);

int main()
{

    int n = 30;
    int m = 10;
    int row = 2;
    int col = 8;
    int k = 7;

    printf("暴力递归：%lf\n", drunkBobWalking_A(n, m, row, col, k));
    printf("记忆化搜索：%lf\n", drunkBobWalking_B(n, m, row, col, k));
    printf("动态规划：%lf\n", drunkBobWalking_C(n, m, row, col, k)); // 可计算k达到500
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
double drunkBobWalking_A(int n, int m, int row, int col, int k)
{
    if (row >= n || row < 0 || col >= m || col < 0 || k < 0)
    {
        return 0.0;
    }
    return dfsDrunkBobWalking_A(n, m, row, col, k) / pow(4, k);
}

double dfsDrunkBobWalking_A(int n, int m, int row, int col, int k)
{
    if (row >= n || row < 0 || col >= m || col < 0 || k < 0)
    {
        return 0.0;
    }
    if (k == 0)
    {
        return 1.0;
    }
    double ans = 0.0;
    ans += dfsDrunkBobWalking_A(n, m, row + 1, col, k - 1);
    ans += dfsDrunkBobWalking_A(n, m, row - 1, col, k - 1);
    ans += dfsDrunkBobWalking_A(n, m, row, col + 1, k - 1);
    ans += dfsDrunkBobWalking_A(n, m, row, col - 1, k - 1);

    return ans;
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
double drunkBobWalking_B(int n, int m, int row, int col, int k)
{
    if (row >= n || row < 0 || col >= m || col < 0 || k < 0)
    {
        return 0.0;
    }
    double ***arr;
    arr = new double **[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double *[m];
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = new double[k + 1];
            for (int l = 0; l < k + 1; l++)
            {
                arr[i][j][l] = 0.0;
            }
        }
    }

    double ans = dfsDrunkBobWalking_B(n, m, row, col, k, arr);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            free(arr[i][j]);
        }
    }
    free(arr);

    return ans / pow(4, k);
}

double dfsDrunkBobWalking_B(int n, int m, int row, int col, int k, double ***arr)
{
    if (row >= n || row < 0 || col >= m || col < 0 || k < 0)
    {
        return 0.0;
    }
    if (k == 0)
    {
        arr[row][col][k] = 1.0;
        return 1.0;
    }

    if (arr[row][col][k] > 0.0)
    {
        return arr[row][col][k];
    }

    double ans = 0.0;
    ans += dfsDrunkBobWalking_B(n, m, row + 1, col, k - 1, arr);
    ans += dfsDrunkBobWalking_B(n, m, row - 1, col, k - 1, arr);
    ans += dfsDrunkBobWalking_B(n, m, row, col + 1, k - 1, arr);
    ans += dfsDrunkBobWalking_B(n, m, row, col - 1, k - 1, arr);

    arr[row][col][k] = ans;
    return ans;
}

// 动态规划：
// Time: O(n * m * k)
// Space: O(n * m * k)
double drunkBobWalking_C(int n, int m, int row, int col, int k)
{
    if (row >= n || row < 0 || col >= m || col < 0 || k < 0)
    {
        return 0.0;
    }
    double ***dp;
    dp = new double **[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new double *[m];
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = new double[k + 1];
            dp[i][j][0] = 1.0;
        }
    }

    for (int t = 1; t <= k; t++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                double cnt = 0.0;
                cnt += pickElementFromArr(dp, i + 1, j, t - 1, n, m);
                cnt += pickElementFromArr(dp, i - 1, j, t - 1, n, m);
                cnt += pickElementFromArr(dp, i, j + 1, t - 1, n, m);
                cnt += pickElementFromArr(dp, i, j - 1, t - 1, n, m);
                dp[i][j][t] = cnt;
            }
        }
    }

    double ans = dp[row][col][k];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            free(dp[i][j]);
        }
    }
    free(dp);

    return ans / pow(4, k);
}

double pickElementFromArr(double ***arr, int i, int j, int cnt, int n, int m)
{
    if (i >= n || i < 0 || j >= m || j < 0)
    {
        return 0.0;
    }
    else
    {
        return arr[i][j][cnt];
    }
}