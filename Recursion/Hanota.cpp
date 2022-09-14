#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      汉诺塔问题

//      在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。
//      一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。
//      移动圆盘时受到以下限制:
//          (1) 每次只能移动一个盘子;
//          (2) 盘子只能从柱子顶端滑出移到下一根柱子;
//          (3) 盘子只能叠在比它大的盘子上。

//      请编写程序，给定一个 n , 用栈将所有盘子从第一根柱子移到最后一根柱子。

//      A 中盘子的数目不大于14个。

//      若要将 所有 的 盘子 搬完，需要 (2 ^ N - 1) 次

int generateRandomNum(int low, int high);
void hanota_A(int n);
void hanotaLeftToRight(int n);
void hanotaLeftToMid(int n);
void hanotaMidToLeft(int n);
void hanotaMidToRight(int n);
void hanotaRightToLeft(int n);
void hanotaRightToMid(int n);

void hanota_B(int n);
void hanotaHelper(int n, string from, string to, string other);

int main()
{
    int n = generateRandomNum(1, 10);
    printf("随机数字为：%d\n", n);
    printf("方法一：\n");
    hanota_A(n);
    printf("方法二：\n");
    hanota_B(n);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 递归一:
// Time: O(2^N)
// Space: O(2^N)
void hanota_A(int n)
{
    hanotaLeftToRight(n);
}

// hanota 从 左 移动 到 右：
void hanotaLeftToRight(int n)
{
    if (n == 1)
    {
        printf("Move %d From Left to Right \n", n);
        return;
    }
    hanotaLeftToMid(n - 1);
    printf("Move %d From Left to Right \n", n);
    hanotaMidToRight(n - 1);
}

// hanota 从 左 移动 到 中：
void hanotaLeftToMid(int n)
{
    if (n == 1)
    {
        printf("Move %d From Left to Mid \n", n);
        return;
    }
    hanotaLeftToRight(n - 1);
    printf("Move %d From Left to Mid \n", n);
    hanotaRightToMid(n - 1);
}

// hanota 从 中 移动 到 左：
void hanotaMidToLeft(int n)
{
    if (n == 1)
    {
        printf("Move %d From Mid to Left \n", n);
        return;
    }
    hanotaMidToRight(n - 1);
    printf("Move %d From Mid to Left \n", n);
    hanotaRightToLeft(n - 1);
}

// hanota 从 中 移动 到 右：
void hanotaMidToRight(int n)
{
    if (n == 1)
    {
        printf("Move %d From Mid to Right \n", n);
        return;
    }
    hanotaMidToLeft(n - 1);
    printf("Move %d From Mid to Right \n", n);
    hanotaLeftToRight(n - 1);
}

// hanota 从 右 移动 到 左：
void hanotaRightToLeft(int n)
{
    if (n == 1)
    {
        printf("Move %d From Right to Left \n", n);
        return;
    }
    hanotaRightToMid(n - 1);
    printf("Move %d From Right to Left \n", n);
    hanotaMidToLeft(n - 1);
}

// hanota 从 右 移动 到 中：
void hanotaRightToMid(int n)
{
    if (n == 1)
    {
        printf("Move %d From Right to Mid \n", n);
        return;
    }
    hanotaRightToLeft(n - 1);
    printf("Move %d From Left to Right \n", n);
    hanotaLeftToMid(n - 1);
}

// 递归二:
// Time: O(2^N)
// Space: O(2^N)
void hanota_B(int n)
{
    hanotaHelper(n, "Left", "Right", "Mid");
}

void hanotaHelper(int n, string from, string to, string other)
{
    if (n == 1)
    {
        printf("Move %d From %s to %s \n", n, from.c_str(), to.c_str());
        return;
    }
    hanotaHelper(n - 1, from, other, to);
    printf("Move %d From %s to %s \n", n, from.c_str(), to.c_str());
    hanotaHelper(n - 1, other, to, from);
}