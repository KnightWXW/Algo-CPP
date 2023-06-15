#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      322. 零钱兑换

//      链接：https://leetcode.cn/problems/coin-change/

//      给你一个整数数组 coins ，表示不同面额的硬币；
//      以及一个整数 amount ，表示总金额。
//      计算并返回可以凑成总金额所需的 最少的硬币个数 。
//      如果没有任何一种硬币组合能组成总金额，返回 -1 。
//      你可以认为每种硬币的数量是无限的。
//      示例 1：
//      输入：coins = [1, 2, 5], amount = 11
//      输出：3
//      解释：11 = 5 + 5 + 1
//      示例 2：
//      输入：coins = [2], amount = 3
//      输出：-1
//      示例 3：
//      输入：coins = [1], amount = 0
//      输出：0
//      提示：
//          1 <= coins.length <= 12
//          1 <= coins[i] <= 231 - 1
//          0 <= amount <= 104

int generateRandomNum(int low, int high);

int coinChange_AA(vector<int> coins, int amount);
int dfsCoinChange_AA(vector<int> coins, int amount, int i);
int coinChange_AB(vector<int> coins, int amount);
int dfsCoinChange_AB(vector<int> coins, int amount, int i, vector<vector<int>> arr);
int coinChange_AC(vector<int> coins, int amount);

int coinChange_BA(vector<int> coins, int amount);
int dfsCoinChange_BA(vector<int> coins, int amount, int n);
int coinChange_BB(vector<int> coins, int amount);
int dfsCoinChange_BB(vector<int> coins, int amount, int n, vector<vector<int>> arr);
int coinChange_BC(vector<int> coins, int amount);
int coinChange_BD(vector<int> coins, int amount);
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = generateRandomNum(10, 100);
    // int amount = 11;
    printf("(暴力递归<一>) 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, coinChange_AA(coins, amount));
    printf("(记忆化搜索<一>) 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, coinChange_AB(coins, amount));
    printf("(动态规划<一>) 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, coinChange_AC(coins, amount));

    printf("(暴力递归<二>) 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, coinChange_BA(coins, amount));
    printf("(记忆化搜索<二>) 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, coinChange_BB(coins, amount));
    printf("(动态规划<二>) 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, coinChange_BC(coins, amount));
    printf("(动态规划[空间压缩]<二>) 凑成总金额为 %d 最少所需 %d 个硬币。\n", amount, coinChange_BD(coins, amount));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 暴力递归<一>：
// Time: O(2^N)
// Space: O(N)
int coinChange_AA(vector<int> coins, int amount)
{
    if (coins.size() == 0)
    {
        return -1;
    }
    return dfsCoinChange_AA(coins, amount, 0);
}

int dfsCoinChange_AA(vector<int> coins, int amount, int i)
{
    if (i >= coins.size())
    {
        return amount == 0 ? 0 : INT_MAX;
    }
    int cnt = INT_MAX;
    for (int p = 0; coins[i] * p <= amount; p++)
    {
        int next = dfsCoinChange_AA(coins, amount - coins[i] * p, i + 1);
        if (next != INT_MAX)
        {
            cnt = min(cnt, next + p);
        }
    }
    return cnt;
}

// 记忆化搜索<一>:
// Time: O(2^N)
// Space: O(N)
int coinChange_AB(vector<int> coins, int amount)
{

    int l = coins.size();
    if (l == 0)
    {
        return -1;
    }
    vector<vector<int>> arr(amount + 1, vector<int>(l + 1, 0));
    return dfsCoinChange_AB(coins, amount, 0, arr);
}

int dfsCoinChange_AB(vector<int> coins, int amount, int i, vector<vector<int>> arr)
{
    if (i >= coins.size())
    {
        if (amount == 0)
        {
            return 0;
        }
        else
        {
            arr[amount][coins.size()] = INT_MAX;
            return INT_MAX;
        }
    }

    if (arr[amount][i] > 0)
    {
        return arr[amount][i];
    }

    int cnt = INT_MAX;
    for (int p = 0; coins[i] * p <= amount; p++)
    {
        int next = dfsCoinChange_AB(coins, amount - coins[i] * p, i + 1, arr);
        if (next != INT_MAX)
        {
            cnt = min(cnt, next + p);
        }
    }
    arr[amount][i] = cnt;
    return cnt;
}

// 动态规划<一>:
// Time: O(N)
// Space: O(N)
int coinChange_AC(vector<int> coins, int amount)
{

    int l = coins.size();
    if (l == 0)
    {
        return -1;
    }
    vector<vector<int>> dp(amount + 1, vector<int>(l + 1, 0));

    for (int i = 1; i <= amount; i++)
    {
        dp[i][l] = INT_MAX;
    }

    for (int a = 0; a <= amount; a++)
    {
        for (int j = l - 1; j >= 0; j--)
        {
            int cnt = INT_MAX;
            for (int p = 0; coins[j] * p <= a; p++)
            {
                int next = dp[a - coins[j] * p][j + 1];
                if (next != INT_MAX)
                {
                    cnt = min(cnt, next + p);
                }
            }
            dp[a][j] = cnt;
        }
    }
    return dp[amount][0];
}

// 假设 amount = 13 , coins = {3, 5}
//  如果 coins[i] == 3, 分别 选择 0、1、2......个 coins[i]
//           (  13     10      7      4     1   )   amount
//
//     i        x       y      z
//   i + 1      a       b      c      d     e
//             b+1     c+1    d+1    e+1
//    求 x , 需要关注 y：
//            x == min(a, y + 1)
//       类比推导：y == min(b, z + 1)
//   边界条件： e > 0：最后一个 coins[i] > amount

// 暴力递归<二>：
// Time: O(2^N)
// Space: O(N)
int coinChange_BA(vector<int> coins, int amount)
{
    int ans = dfsCoinChange_BA(coins, amount, coins.size());
    return ans == INT_MAX - 1 ? -1 : ans;
}

int dfsCoinChange_BA(vector<int> coins, int amount, int n)
{
    if (amount == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return INT_MAX - 1;
    }

    if (coins[n - 1] > amount)
    {
        return dfsCoinChange_BA(coins, amount, n - 1);
    }
    else
    {
        return min(dfsCoinChange_BA(coins, amount, n - 1),
                   dfsCoinChange_BA(coins, amount - coins[n - 1], n) + 1);
    }
}

// 记忆化搜索<二>：
// Time: O(2^N)
// Space: O(N)
int coinChange_BB(vector<int> coins, int amount)
{
    int l = coins.size();
    vector<vector<int>> arr(l + 1, vector<int>(amount + 1, 0));
    int ans = dfsCoinChange_BB(coins, amount, l, arr);
    return ans == INT_MAX - 1 ? -1 : ans;
}

int dfsCoinChange_BB(vector<int> coins, int amount, int n, vector<vector<int>> arr)
{
    if (amount == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        arr[0][amount] = INT_MAX - 1;
        return INT_MAX - 1;
    }

    if (arr[n][amount] > 0)
    {
        return arr[amount][n];
    }

    if (coins[n - 1] > amount)
    {
        arr[n][amount] = dfsCoinChange_BB(coins, amount, n - 1, arr);
        return arr[n][amount];
    }
    else
    {
        int p1 = dfsCoinChange_BB(coins, amount, n - 1, arr);
        int p2 = dfsCoinChange_BB(coins, amount - coins[n - 1], n, arr) + 1;
        arr[n][amount] = min(p1, p2);
        return arr[n][amount];
    }
}

int coinChange_BC(vector<int> coins, int amount)
{
    int l = coins.size();
    vector<vector<int>> dp(l + 1, vector<int>(amount + 1, 0));
    for (int i = 1; i <= amount; i++)
    {
        dp[0][i] = INT_MAX - 1;
    }

    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
    }
    return dp[l][amount] == (INT_MAX - 1) ? -1 : dp[l][amount];
}

int coinChange_BD(vector<int> coins, int amount)
{
    int l = coins.size();
    vector<int> dp(amount + 1, 0);
    for (int i = 1; i <= amount; i++)
    {
        dp[i] = INT_MAX - 1;
    }

    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] > j)
            {
                dp[j] = dp[j];
            }
            else
            {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
    }
    return dp[amount] == (INT_MAX - 1) ? -1 : dp[amount];
}