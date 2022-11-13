#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//      给定一个 正整数N，表示有 N 份 青草 统一堆放在仓库里，
//      有一只牛 和 一只羊，牛先吃，羊后吃，它俩轮流吃草，
//      不管是牛还是羊，每一轮能吃的草量必须是：1，4，16，64 … (4的某次方)
//      谁最先把草吃完，谁获胜，假设牛和羊都绝顶聪明，都想赢，都会做出理性的决定。
//      根据唯一的 参数 N，返回谁会赢。

int generateRandomNum(int low, int high);

string EatingGrass_A(int n);
string EatingGrass_B(int n);

int main()
{
    int n = generateRandomNum(1, 100);
    printf("%d 份 青草, %s 赢。\n", n, EatingGrass_A(n).c_str());
    printf("%d 份 青草, %s 赢。\n", n, EatingGrass_B(n).c_str());
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

// 模拟：
// Time: O(n)
// Space: O(1)
string EatingGrass_A(int n)
{
    if (n < 5)
    {
        if (n == 0 || n == 2)
        {
            return "羊";
        }
        else
        {
            return "牛";
        }
    }
    int base = 1;
    while (base <= n)
    {
        if (EatingGrass_A(n - base) == "羊")
        {
            return "牛";
        }
        // 防止 base * 4 之后 溢出:
        if (base > n / 4)
        {
            break;
        }
        base *= 4;
    }
    return "羊";
}

// 打表 找规律：
// Time: O(n)
// Space: O(1)
string EatingGrass_B(int n)
{
    if (n % 5 == 0 || n % 5 == 2)
    {
        return "羊";
    }
    return "牛";
}