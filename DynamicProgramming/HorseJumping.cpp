#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      在中国象棋的棋盘中，把整个棋盘放入第一象限,
//      棋盘的最左下角是(0.0)位置，整个棋盘就是横坐标上9条线、纵坐标上10条线的区域。
//      给你 三个参数 x, y. k。
//      马走日，返回 “马” 从(O,0)位置出发，必须走 k 步最后落在(x.y)上的方法数有多少种。

int horseJumping_A(int x, int y, int k);
int dfsHorseJumping_A(int x, int y, int i, int j, int cnt);
int horseJumping_B(int x, int y, int k);
int dfsHorseJumping_B(int x, int y, int i, int j, int cnt, int ***arr);
int horseJumping_C(int x, int y, int k);
int dfsHorseJumping_C(int x, int y, int k, int ***dp);
int pickElementFromArr(int ***arr, int i, int j, int cnt);

int main()
{
    int x = 5;
    int y = 5;
    int k = 10;
    printf("暴力递归：%d\n", horseJumping_A(x, y, k));   // 1102475
    printf("记忆化搜索：%d\n", horseJumping_B(x, y, k)); // 1102475
    printf("动态规划：%d\n", horseJumping_C(x, y, k));   // 1102475
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int horseJumping_A(int x, int y, int k)
{
    if (x >= 9 || y >= 10 || x < 0 || y < 0 || k < 0)
    {
        return 0;
    }
    return dfsHorseJumping_A(x, y, 0, 0, k);
}

int dfsHorseJumping_A(int x, int y, int i, int j, int cnt)
{
    if (i >= 9 || j >= 10 || i < 0 || j < 0 || cnt < 0)
    {
        return 0;
    }

    if (cnt == 0)
    {
        if (i == x && j == y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int steps = 0;
    steps += dfsHorseJumping_A(x, y, i + 1, j + 2, cnt - 1);
    steps += dfsHorseJumping_A(x, y, i + 2, j + 1, cnt - 1);
    steps += dfsHorseJumping_A(x, y, i + 2, j - 1, cnt - 1);
    steps += dfsHorseJumping_A(x, y, i + 1, j - 2, cnt - 1);
    steps += dfsHorseJumping_A(x, y, i - 1, j - 2, cnt - 1);
    steps += dfsHorseJumping_A(x, y, i - 2, j - 1, cnt - 1);
    steps += dfsHorseJumping_A(x, y, i - 2, j + 1, cnt - 1);
    steps += dfsHorseJumping_A(x, y, i - 1, j + 2, cnt - 1);
    return steps;
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(9 * 10 * k)
int horseJumping_B(int x, int y, int k)
{
    if (x >= 9 || y >= 10 || x < 0 || y < 0 || k <= 0)
    {
        return 0;
    }

    int ***arr;
    arr = new int **[9];
    for (int i = 0; i < 9; i++)
    {
        arr[i] = new int *[10];
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = new int[k + 1];
            for (int l = 0; l < k + 1; l++)
            {
                arr[i][j][l] = 0;
            }
        }
    }

    int ans = dfsHorseJumping_B(x, y, 0, 0, k, arr);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            free(arr[i][j]);
        }
    }
    free(arr);
    return ans;
}

int dfsHorseJumping_B(int x, int y, int i, int j, int cnt, int ***arr)
{
    if (i >= 9 || j >= 10 || i < 0 || j < 0 || cnt < 0)
    {
        return 0;
    }

    if (arr[i][j][cnt] != 0)
    {
        return arr[i][j][cnt];
    }

    if (cnt == 0)
    {
        if (i == x && j == y)
        {
            arr[i][j][cnt] = 1;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int steps = 0;
    steps += dfsHorseJumping_B(x, y, i + 1, j + 2, cnt - 1, arr);
    steps += dfsHorseJumping_B(x, y, i + 2, j + 1, cnt - 1, arr);
    steps += dfsHorseJumping_B(x, y, i + 2, j - 1, cnt - 1, arr);
    steps += dfsHorseJumping_B(x, y, i + 1, j - 2, cnt - 1, arr);
    steps += dfsHorseJumping_B(x, y, i - 1, j - 2, cnt - 1, arr);
    steps += dfsHorseJumping_B(x, y, i - 2, j - 1, cnt - 1, arr);
    steps += dfsHorseJumping_B(x, y, i - 2, j + 1, cnt - 1, arr);
    steps += dfsHorseJumping_B(x, y, i - 1, j + 2, cnt - 1, arr);

    arr[i][j][cnt] = steps;
    return steps;
}

// 动态规划：
// Time: O(k * 9 * 10)
// Space: O(k * 9 * 10)
int horseJumping_C(int x, int y, int k)
{
    if (x >= 9 || y >= 10 || x < 0 || y < 0 || k < 0)
    {
        return 0;
    }
    int ***dp;
    dp = new int **[9];
    for (int i = 0; i < 9; i++)
    {
        dp[i] = new int *[10];
        for (int j = 0; j < 10; j++)
        {
            dp[i][j] = new int[k + 1];
            for (int l = 0; l < k + 1; l++)
            {
                dp[i][j][l] = 0;
            }
        }
    }

    int ans = dfsHorseJumping_C(x, y, k, dp);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            free(dp[i][j]);
        }
    }
    free(dp);
    return ans;
}

int dfsHorseJumping_C(int x, int y, int k, int ***dp)
{
    dp[x][y][0] = 1;
    for (int cnt = 1; cnt <= k; cnt++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                int steps = 0;
                steps += pickElementFromArr(dp, i + 1, j + 2, cnt - 1);
                steps += pickElementFromArr(dp, i + 2, j + 1, cnt - 1);
                steps += pickElementFromArr(dp, i + 2, j - 1, cnt - 1);
                steps += pickElementFromArr(dp, i + 1, j - 2, cnt - 1);
                steps += pickElementFromArr(dp, i - 1, j - 2, cnt - 1);
                steps += pickElementFromArr(dp, i - 2, j - 1, cnt - 1);
                steps += pickElementFromArr(dp, i - 2, j + 1, cnt - 1);
                steps += pickElementFromArr(dp, i - 1, j + 2, cnt - 1);
                dp[i][j][cnt] = steps;
            }
        }
    }
    return dp[0][0][k];
}

int pickElementFromArr(int ***arr, int i, int j, int cnt)
{
    if (i >= 9 || i < 0 || j >= 10 || j < 0)
    {
        return 0;
    }
    else
    {
        return arr[i][j][cnt];
    }
}