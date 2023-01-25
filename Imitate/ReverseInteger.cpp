#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      LeetCode 7. 整数反转

//      链接：https://leetcode.cn/problems/reverse-integer/

//      给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//      如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
//      假设环境不允许存储 64 位整数（有符号或无符号）。
//      示例 1：
//          输入：x = 123
//          输出：321
//      示例 2：
//          输入：x = -123
//          输出：-321
//      示例 3：
//          输入：x = 120
//          输出：21
//      示例 4：
//          输入：x = 0
//          输出：0
//      提示：
//          -231 <= x <= 231 - 1

int generateRandomNum(int low, int high);

int ReverseInteger(int x);

int main()
{
    int x = generateRandomNum(-999999999, 999999999);
    int ans = ReverseInteger(x);
    printf("将 %d 中的数字部分反转后的结果 %d\n", x, ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

int ReverseInteger(int x)
{
    bool flag = ((x >> 31) & 1) == 1;
    x = flag == true ? x : -x;
    int ans = 0;
    int divide = INT_MIN / 10;
    int remainder = INT_MIN % 10;

    while (x != 0)
    {
        if (ans < divide || (ans == divide && x % 10 < remainder))
        {
            return 0;
        }
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return flag == true ? ans : -ans;
}