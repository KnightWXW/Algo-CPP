#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 172. 阶乘后的零

//      链接：https://leetcode.cn/problems/factorial-trailing-zeroes/

//      给定一个整数 n ，返回 n! 结果中尾随零的数量。
//      提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
//      示例 1：
//          输入：n = 3
//          输出：0
//          解释：3! = 6 ，不含尾随 0
//      示例 2：
//          输入：n = 5
//          输出：1
//          解释：5! = 120 ，有一个尾随 0
//      示例 3：
//          输入：n = 0
//          输出：0
//      提示：
//          0 <= n <= 104

int generateRandomNum(int low, int high);

int TrailingZeroes_A(int n);
int TrailingZeroes_B(int n);
int TrailingZeroes_C(int n);

int main()
{
    int num = generateRandomNum(1, 3999);
    int ans_A = TrailingZeroes_A(num);
    int ans_B = TrailingZeroes_B(num);
    int ans_C = TrailingZeroes_C(num);
    printf(" %d! 结果中尾随零的数量为 %d \n", num, ans_A);
    printf(" %d! 结果中尾随零的数量为 %d \n", num, ans_B);
    printf(" %d! 结果中尾随零的数量为 %d \n", num, ans_C);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

int TrailingZeroes_A(int n)
{
    int five = 0;
    for (int k = n; k >= 1; k--)
    {
        int tem = k;
        while (tem != 0)
        {
            if (tem % 5 == 0)
            {
                five++;
                tem /= 5;
            }
            else
            {
                break;
            }
        }
    }
    return five;
}

int TrailingZeroes_B(int n)
{
    int five = 0;
    while (n != 0)
    {
        n /= 5;
        five += n;
    }
    return five;
}

int TrailingZeroes_C(int n)
{
    int ans = 0;
    int k = 5;
    while (k <= n)
    {
        ans += n / k;
        k *= 5;
    }
    return ans;
}