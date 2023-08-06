#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 991. 坏了的计算器

//      链接：https://leetcode.cn/problems/broken-calculator/

//      在显示着数字 startValue 的坏计算器上，我们可以执行以下两种操作：
//          双倍（Double）：将显示屏上的数字乘 2；
//          递减（Decrement）：将显示屏上的数字减 1 。
//      给定两个整数 startValue 和 target 。返回显示数字 target 所需的最小操作数。
//      示例 1：
//          输入：startValue = 2, target = 3
//          输出：2
//          解释：先进行双倍运算，然后再进行递减运算 {2 -> 4 -> 3}.
//      示例 2：
//          输入：startValue = 5, target = 8
//          输出：2
//          解释：先递减，再双倍 {5 -> 4 -> 8}.
//      示例 3：
//          输入：startValue = 3, target = 10
//          输出：3
//          解释：先双倍，然后递减，再双倍 {3 -> 6 -> 5 -> 10}.
//      提示：
//          1 <= startValue, target <= 109

int generateRandomNum(int low, int high);

int BrokenCalc(int startValue, int target);

int main()
{
    int startValue = generateRandomNum(1, 9999);
    int target = generateRandomNum(1, 99999999);
    int ans_A = BrokenCalc(startValue, target);
    printf("从数字 %d 到数字 %d 所需的最小操作数为 %d。\n", startValue, target, ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 贪心算法：
// 逆向思维：
//      除了对 X 执行乘 2 或 减 1 操作之外，
//      也可以对 Y 执行除 2（当 Y 是偶数时）或者加 1 操作。
// Time：O(N)
// Space: O(1)
int BrokenCalc(int startValue, int target)
{
    int cnt = 0;
    while (startValue != target)
    {
        if (startValue > target)
        {
            cnt += (startValue - target);
            break;
        }
        else if ((target & 1) == 0)
        {
            target >>= 1;
            cnt++;
        }
        else
        {
            target++;
            cnt++;
        }
    }
    return cnt;
}