#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      斐波那契数（通常用 F(n) 表示）形成的序列称为 斐波那契数列。
//      该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
//      F(0) = 0，F(1) = 1;
//      F(n) = F(n - 1) + F(n - 2)，其中 n > 1;
//      给定n ，请计算 F(n) 。

int generateRandomNum(int low, int high);
int fibonacci_A(int n);
int fibonacci_B(int n);
int dfsFibonacci_B(int n, unordered_map<int, int> hashMap);
int fibonacci_C(int n);
int fibonacci_D(int n);

int main()
{
    int num = generateRandomNum(0, 30);
    printf("随机数字为：%d\n", num);
    printf("暴力递归：%d\n", fibonacci_A(num));
    printf("记忆化搜索：%d\n", fibonacci_B(num));
    printf("动态规划：%d\n", fibonacci_C(num));
    printf("动态规划（空间优化）：%d\n", fibonacci_A(num));
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
    unordered_map<int, int> hashMap;
    hashMap[0] = 0;
    hashMap[1] = 1;
    return dfsFibonacci_B(n, hashMap);
}

int dfsFibonacci_B(int n, unordered_map<int, int> hashMap)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int p1 = 0;
    int p2 = 0;
    if (hashMap[n - 1] > 0)
    {
        p1 = hashMap[n - 1];
    }
    else
    {
        p1 = dfsFibonacci_B(n - 1, hashMap);
    }

    if (hashMap[n - 2] > 0)
    {
        p2 = hashMap[n - 2];
    }
    else
    {
        p2 = dfsFibonacci_B(n - 2, hashMap);
    }

    hashMap[n] = p1 + p2;
    return hashMap[n];
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
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
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