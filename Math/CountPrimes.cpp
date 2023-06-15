#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode204. 计数质数

//      链接：https://leetcode.cn/problems/count-primes/

//      给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
//      示例 1：
//          输入：n = 10
//          输出：4
//          解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
//      示例 2：
//          输入：n = 0
//          输出：0
//      示例 3：
//          输入：n = 1
//          输出：0
//      提示：
//          0 <= n <= 5 * 106

int generateRandomNum(int low, int high);
void printBool(bool b);

int CountPrimes_A(int n);
int CountPrimes_B(int n);

int main()
{
    int n = generateRandomNum(1, 99999999);
    bool ans_A = CountPrimes_A(n);
    bool ans_B = CountPrimes_B(n);
    printf("所有小于非负整数 %d 的质数的数量 为 %d\n", n, ans_A);
    printf("所有小于非负整数 %d 的质数的数量 为 %d\n", n, ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 枚举：
bool IsPrime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int CountPrimes_A(int n)
{
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        ans += (IsPrime(i) ? 1 : 0);
    }
    return ans;
}

// 埃氏筛：
int CountPrimes_B(int n)
{
    vector<bool> isPrime(n, true);
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            ans++;
            if ((long long)i * i < n)
            {
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
    return ans;
}