#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//      LeetCode 2038. 如果相邻两个颜色均相同则删除当前颜色

//      链接：https://leetcode.cn/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

//      总共有 n 个颜色片段排成一列，每个颜色片段要么是 'A' 要么是 'B' 。
//      给你一个长度为 n 的字符串 colors ，其中 colors[i] 表示第 i 个颜色片段的颜色。
//      Alice 和 Bob 在玩一个游戏，他们 轮流 从这个字符串中删除颜色。Alice 先手 。
//      如果一个颜色片段为 'A' 且 相邻两个颜色 都是颜色 'A' ，
//      那么 Alice 可以删除该颜色片段。Alice 不可以 删除任何颜色 'B' 片段。
//      如果一个颜色片段为 'B' 且 相邻两个颜色 都是颜色 'B' ，
//      那么 Bob 可以删除该颜色片段。Bob 不可以 删除任何颜色 'A' 片段。
//      Alice 和 Bob 不能 从字符串两端删除颜色片段。
//      如果其中一人无法继续操作，则该玩家 输 掉游戏且另一玩家 获胜 。
//      假设 Alice 和 Bob 都采用最优策略，如果 Alice 获胜，请返回 true，
//      否则 Bob 获胜，返回 false。
//      示例 1：
//          输入：colors = "AAABABB"
//          输出：true
//      解释：
//          AAABABB -> AABABB
//          Alice 先操作。
//          她删除从左数第二个 'A' ，这也是唯一一个相邻颜色片段都是 'A' 的 'A' 。
//          现在轮到 Bob 操作。
//          Bob 无法执行任何操作，因为没有相邻位置都是 'B' 的颜色片段 'B' 。
//          因此，Alice 获胜，返回 true 。
//      示例 2：
//          输入：colors = "AA"
//          输出：false
//      解释：
//          Alice 先操作。
//          只有 2 个 'A' 且它们都在字符串的两端，所以她无法执行任何操作。
//          因此，Bob 获胜，返回 false 。
//      示例 3：
//          输入：colors = "ABBBBBBBAAA"
//          输出：false
//      解释：
//          ABBBBBBBAAA -> ABBBBBBBAA
//          Alice 先操作。
//          她唯一的选择是删除从右数起第二个 'A' 。
//          ABBBBBBBAA -> ABBBBBBAA
//          接下来轮到 Bob 操作。
//          他有许多选择，他可以选择任何一个 'B' 删除。
//          然后轮到 Alice 操作，她无法删除任何片段。
//          所以 Bob 获胜，返回 false 。
//      提示：
//          1 <= colors.length <= 105
//          colors 只包含字母 'A' 和 'B'

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
void printBool(bool b);

bool WinnerOfGame(string colors);

int main()
{
    int n = generateRandomNum(2, 30);
    string s = generateRandomString(n);
    printString(s);
    int ans = WinnerOfGame(s);
    printf("如果 Alice 获胜，请返回 true, 否则 Bob 获胜，返回 false。\n");
    printBool(ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

string generateRandomString(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "AB";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
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

// 贪心：
// Time: O(N)
// Space: O(1)
bool WinnerOfGame(string colors)
{
    int l = colors.size();
    int cntA = 0;
    int cntB = 0;
    for (int i = 1; i < l - 1; i++)
    {
        if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A')
        {
            cntA++;
        }
        if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B')
        {
            cntB++;
        }
    }
    return cntA > cntB;
}