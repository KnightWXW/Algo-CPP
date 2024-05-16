#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//      LeetCode 292. Nim 游戏

//      链接：https://leetcode.cn/problems/nim-game/

//      你和你的朋友，两个人一起玩 Nim 游戏：
//      桌子上有一堆石头。
//      你们轮流进行自己的回合， 你作为先手 。
//      每一回合，轮到的人拿掉 1 - 3 块石头。
//      拿掉最后一块石头的人就是获胜者。
//      假设你们每一步都是最优解。
//      请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。
//      如果可以赢，返回 true；否则，返回 false 。
//      示例 1：
//          输入：n = 4
//          输出：false 
//          解释：以下是可能的结果:
//              1. 移除1颗石头。你的朋友移走了3块石头，包括最后一块。你的朋友赢了。
//              2. 移除2个石子。你的朋友移走2块石头，包括最后一块。你的朋友赢了。
//              3.你移走3颗石子。你的朋友移走了最后一块石头。你的朋友赢了。
//              在所有结果中，你的朋友是赢家。
//      示例 2：
//          输入：n = 1
//          输出：true
//      示例 3：
//          输入：n = 2
//          输出：true
//      提示：
//          1 <= n <= 231 - 1

int generateRandomNum(int low, int high);

bool CanWinNimGame(int n);
void printBool(bool b);

int main()
{
    int num = generateRandomNum(1, 99999999);
    bool ans_A = CanWinNimGame(num);
    printf("在给定石头数量为 %d 的情况下可否赢得游戏 \n", num);
    printBool(ans_A);
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

// 数学：
// Time: O(1)
// Space: O(1)
//      如果总的石头数目为 4 的倍数时，
//      因为无论你取多少石头，对方总有对应的取法，
//      让剩余的石头的数目继续为 4 的倍数。
//      对于你或者你的对手取石头时，显然最优的选择是当前己方取完石头后，
//      让剩余的石头的数目为 4 的倍数。
//      假设当前的石头数目为 x，如果 x 为 4 的倍数时，则此时你必然会输掉游戏；
//      如果 x 不为 4 的倍数时，则此时你只需要取走 x mod 4 个石头时，
//      则剩余的石头数目必然为 4 的倍数，从而对手会输掉游戏。
bool CanWinNimGame(int n)
{
    return n % 4 != 0;
}