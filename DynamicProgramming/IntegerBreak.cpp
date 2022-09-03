#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

//      LeetCode 343. 整数拆分

//      链接：https://leetcode.cn/problems/integer-break/

//      给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
//      返回 你可以获得的最大乘积 。

//      示例 1:
//      输入: n = 2
//      输出: 1
//      解释: 2 = 1 + 1, 1 × 1 = 1。

//      示例 2:
//      输入: n = 10
//      输出: 36
//      解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

//      提示:
//          2 <= n <= 58

int generateRandomNum(int low, int high);
int integerBreak_A(int n);
int dfsIntegerBreak_A(int n);
int integerBreak_B(int n);
int dfsIntegerBreak_B(int n, vector<int> & arr);
int integerBreak_C(int n);
int integerBreak_D(int n);

int main()
{
    int n = generateRandomNum(2, 58);
    printf("<暴力递归> 整数 %d 分割得到的最大乘积 为 %d。\n", n, integerBreak_A(n));
    printf("<记忆化搜索> 整数 %d 分割得到的最大乘积 为 %d。\n", n, integerBreak_B(n));
    printf("<动态规划> 整数 %d 分割得到的最大乘积 为 %d。\n", n, integerBreak_C(n));
    printf("<贪心算法> 整数 %d 分割得到的最大乘积 为 %d。\n", n, integerBreak_D(n));
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

// 暴力递归 (一) :
// Time: O(2^N)
// Space: O(N)
int integerBreak_A(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }
    return dfsIntegerBreak_A(n);
}

int dfsIntegerBreak_A(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n <= 3)
    {
        return n;
    }

    int p1 = dfsIntegerBreak_A(n - 1) * 1;
    int p2 = dfsIntegerBreak_A(n - 2) * 2;
    int p3 = dfsIntegerBreak_A(n - 3) * 3;

    return max(max(p1, p2), p3);
}

// 记忆化搜索 (一) :
// Time: O(2^N)
// Space: O(N)
int integerBreak_B(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }
    vector<int> arr(n + 1, 0);
    return dfsIntegerBreak_B(n, arr);
}

int dfsIntegerBreak_B(int n, vector<int> & arr)
{
    if (n == 0)
    {
        arr[0] = 1;
        return 1;
    }
    else if (n <= 3)
    {
        arr[n] = n;
        return n;
    }

    if (arr[n] > 0)
    {
        return arr[n];
    }

    int p1 = dfsIntegerBreak_B(n - 1, arr) * 1;
    int p2 = dfsIntegerBreak_B(n - 2, arr) * 2;
    int p3 = dfsIntegerBreak_B(n - 3, arr) * 3;

    return max(max(p1, p2), p3);
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int integerBreak_C(int n){
    if (n <= 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i = 4; i <= n; i++){
        for(int j = 1; j <= 3 ; j++){
            dp[i] = max(dp[i - j] * j, dp[i]);
        }
    }
    return dp[n];
}

// 贪心算法：
// Time: O(1)
// Space: O(1)
int integerBreak_D(int n){
    if (n <= 3)
    {
        return n - 1;
    }

    int k = n / 3;
    int remind = n % 3;
    if(remind == 0){
        return int(pow(double(3), double(k)));
    }else if(remind == 1){
        return int(pow(double(3), double(k - 1)) * 4);
    }else {
        return int(pow(double(3), double(k)) * 2);
    }
}