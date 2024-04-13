#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      LeetCode 2141. 同时运行 N 台电脑的最长时间

//      链接：https://leetcode.cn/problems/maximum-running-time-of-n-computers/

//      你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries ，
//      其中第 i 个电池可以让一台电脑 运行 batteries[i] 分钟。
//      你想使用这些电池让 全部 n 台电脑 同时 运行。
//      一开始，你可以给每台电脑连接 至多一个电池 。
//      然后在任意整数时刻，你都可以将一台电脑与它的电池断开连接，并连接另一个电池，
//      你可以进行这个操作 任意次 。
//      新连接的电池可以是一个全新的电池，也可以是别的电脑用过的电池。
//      断开连接和连接新的电池不会花费任何时间。
//      注意，你不能给电池充电。
//      请你返回你可以让 n 台电脑同时运行的 最长 分钟数。
//      示例 1：
//          输入：n = 2, batteries = [3,3,3]
//          输出：4
//          解释：
//              一开始，将第一台电脑与电池 0 连接，第二台电脑与电池 1 连接。
//              2 分钟后，将第二台电脑与电池 1 断开连接，并连接电池 2 。
//              注意，电池 0 还可以供电 1 分钟。
//              在第 3 分钟结尾，你需要将第一台电脑与电池 0 断开连接，然后连接电池 1 。
//              在第 4 分钟结尾，电池 1 也被耗尽，第一台电脑无法继续运行。
//              我们最多能同时让两台电脑同时运行 4 分钟，所以我们返回 4 。
//      示例 2：
//          输入：n = 2, batteries = [1,1,1,1]
//          输出：2
//          解释：
//              一开始，将第一台电脑与电池 0 连接，第二台电脑与电池 2 连接。
//              一分钟后，电池 0 和电池 2 同时耗尽，所以你需要将它们断开连接，
//              并将电池 1 和第一台电脑连接，电池 3 和第二台电脑连接。
//              1 分钟后，电池 1 和电池 3 也耗尽了，所以两台电脑都无法继续运行。
//              我们最多能让两台电脑同时运行 2 分钟，所以我们返回 2 。
//      提示：
//          1 <= n <= batteries.length <= 105
//          1 <= batteries[i] <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);
void printBool(bool b);

long long MaxRunTime(int n, vector<int>& batteries);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(1, 50, n);
    int k = generateRandomNum(1, 30);
    printVec(vec);
    long long ans = MaxRunTime(k, vec);
    printf("让 n 台电脑同时运行的 最长 分钟数 为 %ld。\n");
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

long long MaxRunTime(int n, vector<int>& batteries)
{

}