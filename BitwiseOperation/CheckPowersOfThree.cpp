#include <ctime>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>

using namespace std;

//      LeetCode 1780. 判断一个数字是否可以表示成三的幂的和

//      链接: https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/

//      给你一个整数 n ，如果你可以将 n 表示成若干个不同的三的幂之和，请你返回 true ，
//      否则请返回 false 。
//      对于一个整数 y ，如果存在整数 x 满足 y == 3x ，我们称这个整数 y 是三的幂。
//      示例 1：
//          输入：n = 12
//          输出：true
//          解释：12 = 31 + 32
//      示例 2：
//          输入：n = 91
//          输出：true
//          解释：91 = 30 + 32 + 34
//      示例 3：
//          输入：n = 21
//          输出：false
//      提示：
//          1 <= n <= 107

int generateRandomNum(int low, int high);
void printBool(bool b);

bool CheckPowersOfThree(int n);

int main()
{
    int n = generateRandomNum(1, 100000000);
    bool ans_A = CheckPowersOfThree(n);
    printf("%d 能否表示成若干个不同的 3 的幂之和。\n", n);
    printBool(ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

// 位运算(进制转换)：
bool CheckPowersOfThree(int n)
{
    while (n)
    {
        if (n % 3 == 2)
        {
            return false;
        }
        n /= 3;
    }
    return true;
}