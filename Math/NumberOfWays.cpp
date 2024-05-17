#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

//      LeetCode 2147. 分隔长廊的方案数

//      链接：https://leetcode.cn/problems/number-of-ways-to-divide-a-long-corridor/

//      在一个图书馆的长廊里，有一些座位和装饰植物排成一列。
//      给你一个下标从 0 开始，长度为 n 的字符串 corridor ，它包含字母 'S' 和 'P'，
//      其中每个 'S' 表示一个座位，每个 'P' 表示一株植物。
//      在下标 0 的左边和下标 n - 1 的右边 已经 分别各放了一个屏风。
//      你还需要额外放置一些屏风。
//      每一个位置 i - 1 和 i 之间（1 <= i <= n - 1），至多能放一个屏风。
//      请你将走廊用屏风划分为若干段，且每一段内都 恰好有两个座位 ，
//      而每一段内植物的数目没有要求。可能有多种划分方案，
//      如果两个方案中有任何一个屏风的位置不同，那么它们被视为 不同 方案。
//      请你返回划分走廊的方案数。
//      由于答案可能很大，请你返回它对 109 + 7 取余 的结果。
//      如果没有任何方案，请返回 0 。
//      示例 1：
//          输入：corridor = "SSPPSPS"
//          输出：3
//          解释：总共有 3 种不同分隔走廊的方案。
//              上图中黑色的竖线表示已经放置好的屏风。
//              上图每种方案中，每一段都恰好有 两个 座位。
//      示例 2：
//          输入：corridor = "PPSPSP"
//          输出：1
//          解释：只有 1 种分隔走廊的方案，就是不放置任何屏风。
//              放置任何的屏风都会导致有一段无法恰好有 2 个座位。
//      示例 3：
//          输入：corridor = "S"
//          输出：0
//          解释：没有任何方案，因为总是有一段无法恰好有 2 个座位。
//      提示：
//          n == corridor.length
//          1 <= n <= 105
//          corridor[i] 要么是 'S' ，要么是 'P' 。

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int NumberOfWays(string corridor);

int main()
{
    int n = generateRandomNum(0, 20);
    string s = generateRandomString(n);
    printf("图书馆的长廊 的 排列情况 为：");
    printString(s);
    printf("划分走廊的方案数为 %d。", NumberOfWays(s));
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
    char arr[] = "SP";
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

int NumberOfWays(string corridor)
{
    int n = corridor.size();
    int numS = 0;
    for (auto v : corridor)
    {
        if (v == 'S')
        {
            numS++;
        }
    }

    if ((numS & 1) == 1)
    {
        return 0;
    }
    if (numS == 0)
    {
        return 0;
    }
    if (numS == 2)
    {
        return 1;
    }

    int cntS = 0;
    int pre = -1;
    long ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (corridor[i] == 'S')
        {
            if ((cntS >= 2) && (cntS & 1) == 0)
            {
                ans *= (i - pre);
                ans %= MOD;
            }
            cntS++;
            pre = i;
        }
    }
    return int(ans);
}