#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <algorithm>

using namespace std;

//      LeetCode 202. 快乐数

//      链接：https://leetcode.cn/problems/happy-number/

//      编写一个算法来判断一个数 n 是不是快乐数。
//      「快乐数」 定义为：
//      对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//      然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//      如果这个过程 结果为 1，那么这个数就是快乐数。
//      如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
//      示例 1：
//          输入：n = 19
//          输出：true
//          解释：
//              12 + 92 = 82
//              82 + 22 = 68
//              62 + 82 = 100
//              12 + 02 + 02 = 1
//      示例 2：
//          输入：n = 2
//          输出：false
//      提示：
//          1 <= n <= 231 - 1

int generateRandomNum(int low, int high);
void printBool(bool b);

bool IsHappy_A(int n);
bool IsHappy_B(int n);

int main()
{
    int n = generateRandomNum(1, 99999999);
    bool ans_A = IsHappy_A(n);
    bool ans_B = IsHappy_B(n);
    printf("%d 为快乐数吗？\n", n);
    printBool(ans_A);
    printBool(ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
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

bool IsHappy_A(int n)
{
    unordered_set<int> hset;
    while (n != 1)
    {
        int sum = 0;
        while (n != 0)
        {
            int tem = n % 10;
            sum += tem * tem;
            n /= 10;
        }
        n = sum;
        if (hset.count(n) > 0)
        {
            break;
        }
        hset.insert(n);
    }
    return n == 1;
}

// 定律：每一次将该数替换为它每个位置上的数字的平方和，
//      最后的结果不是 1 就是 4。
bool IsHappy_B(int n)
{
    while (n != 1 && n != 4)
    {
        int sum = 0;
        while (n != 0)
        {
            int tem = n % 10;
            sum += tem * tem;
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}