#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//      LeetCode 2320. 统计放置房子的方式数

//      链接：https://leetcode.cn/problems/count-number-of-ways-to-place-houses/

//      一条街道上共有 n * 2 个 地块 ，街道的两侧各有 n 个地块。
//      每一边的地块都按从 1 到 n 编号。每个地块上都可以放置一所房子。
//      现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目。
//      由于答案可能很大，需要对 109 + 7 取余后再返回。
//      注意，如果一所房子放置在这条街某一侧上的第 i 个地块，
//      不影响在另一侧的第 i 个地块放置房子。
//      示例 1：
//          输入：n = 1
//          输出：4
//          解释：
//              可能的放置方式：
//                  1. 所有地块都不放置房子。
//                  2. 一所房子放在街道的某一侧。
//                  3. 一所房子放在街道的另一侧。
//                  4. 放置两所房子，街道两侧各放置一所。
//      示例 2：
//          输入：n = 2
//          输出：9
//          解释：如上图所示，共有 9 种可能的放置方式。
//      提示：
//          1 <= n <= 104

const int CONST_NUM = 1000000007;

int generateRandomNum(int low, int high);

int CountHousePlacements_A(int n);
long long CountHousePlacements_Helper_A(int n);
int CountHousePlacements_B(int n);
int CountHousePlacements_C(int n);

int main()
{
    int n = generateRandomNum(1, 20);
    int ans_A = CountHousePlacements_A(n);
    int ans_B = CountHousePlacements_B(n);
    int ans_C = CountHousePlacements_C(n);
    printf("街道的两侧各有 %d 个地块, 放置房屋的方式数目为: %d\n", n, ans_A);
    printf("街道的两侧各有 %d 个地块, 放置房屋的方式数目为: %d\n", n, ans_B);
    printf("街道的两侧各有 %d 个地块, 放置房屋的方式数目为: %d\n", n, ans_C);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
long long CountHousePlacements_Helper_A(int n)
{
    if (n == 1)
    {
        return 2;
    }
    if (n == 2)
    {
        return 3;
    }
    return CountHousePlacements_Helper_A(n - 1) + CountHousePlacements_Helper_A(n - 2);
}

int CountHousePlacements_A(int n)
{
    long long num = CountHousePlacements_Helper_A(n);
    return (int)(num * num % CONST_NUM);
}

// 动态规划:
// Time: O(N)
// Space: O(N)
int CountHousePlacements_B(int n)
{
    if (n == 1)
    {
        return 4;
    }
    if (n == 2)
    {
        return 9;
    }
    vector<long long> dp(n + 1);
    dp[1] = 2;
    dp[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % CONST_NUM;
    }
    return (int)(dp[n] * dp[n] % CONST_NUM);
}

// 动态规划(空间优化):
// Time: O(N)
// Space: O(1)
int CountHousePlacements_C(int n)
{
    if (n == 1)
    {
        return 4;
    }
    if (n == 2)
    {
        return 9;
    }
    long long a = 2;
    long long b = 3;
    for (int i = 3; i <= n; i++)
    {
        long long c = (a + b) % CONST_NUM;
        a = b;
        b = c;
    }
    return (int)(b * b % CONST_NUM);
}