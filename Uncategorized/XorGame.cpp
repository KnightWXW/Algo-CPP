#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 810. 黑板异或游戏

//      链接：https://leetcode.cn/problems/chalkboard-xor-game/

//      黑板上写着一个非负整数数组 nums[i] 。
//      Alice 和 Bob 轮流从黑板上擦掉一个数字，Alice 先手。
//      如果擦除一个数字后，剩余的所有数字按位异或运算得出的结果等于 0 的话，当前玩家游戏失败。 
//      另外，如果只剩一个数字，按位异或运算得到它本身；如果无数字剩余，按位异或运算结果为 0。
//      并且，轮到某个玩家时，如果当前黑板上所有数字按位异或运算结果等于 0 ，这个玩家获胜。
//      假设两个玩家每步都使用最优解，当且仅当 Alice 获胜时返回 true。
//      示例 1：
//          输入: nums = [1,1,2]
//          输出: false
//          解释: 
//              Alice 有两个选择: 擦掉数字 1 或 2。
//              如果擦掉 1, 数组变成 [1, 2]。剩余数字按位异或得到 1 XOR 2 = 3。
//              那么 Bob 可以擦掉任意数字，因为 Alice 会成为擦掉最后一个数字的人，她总是会输。
//              如果 Alice 擦掉 2，那么数组变成[1, 1]。剩余数字按位异或得到 1 XOR 1 = 0。
//              Alice 仍然会输掉游戏。
//      示例 2:
//          输入: nums = [0,1]
//          输出: true
//      示例 3:
//          输入: nums = [1,2,3]
//          输出: true
//      提示：
//          1 <= nums.length <= 1000
//          0 <= nums[i] < 216

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);
void printBool(bool b);

bool XorGame(vector<int>& nums);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(0, 1000, n); 
    printVecElement(vec);
    bool ans = XorGame(vec);
    printf("Alice是否能获胜: \n");
    printBool(ans);
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

void printVecElement(vector<int> &vec)
{
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
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

bool XorGame(vector<int>& nums)
{
    
}