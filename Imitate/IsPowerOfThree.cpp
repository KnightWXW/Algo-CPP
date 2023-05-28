#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode 326. 3 的幂

//      链接：https://leetcode.cn/problems/power-of-three/

//      给定一个整数，写一个函数来判断它是否是 3 的幂次方。
//      如果是，返回 true ；否则，返回 false 。
//      整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x
//      示例 1：
//          输入：n = 27
//          输出：true
//      示例 2：
//          输入：n = 0
//          输出：false
//      示例 3：
//          输入：n = 9
//          输出：true
//      示例 4：
//          输入：n = 45
//          输出：false
//      提示：
//          -231 <= n <= 231 - 1
//      进阶：你能不使用循环或者递归来完成本题吗？

bool IsPowerOfThree_A(int n);
bool IsPowerOfThree_B(int n);

int generateRandomNum(int low, int high);
void printBool(bool b);

int main()
{
    int n = generateRandomNum(-10000, 10000);
    bool ans_A = IsPowerOfThree_A(n);
    bool ans_B = IsPowerOfThree_B(n);
    printf("此数 %d 是否是 3 的幂次方: \n");
    printBool(ans_A);
    printBool(ans_B);
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

bool IsPowerOfThree_A(int n)
{
    while (n && n % 3 == 0)
    {
        n /= 3;
    }
    return n == 1;
}

bool IsPowerOfThree_B(int n)
{
    return (n > 0) && (1162261467 % n == 0);
}