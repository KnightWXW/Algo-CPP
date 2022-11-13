#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 45. 跳跃游戏 II

//      链接：https://leetcode.cn/problems/jump-game-ii/

//      给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
//      数组中的每个元素代表你在该位置可以跳跃的最大长度。
//      你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//      假设你总是可以到达数组的最后一个位置。

//      示例 1:
//      输入: nums = [2,3,1,1,4]
//      输出: 2
//      解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

//      示例 2:
//      输入: nums = [2,3,0,1,4]
//      输出: 2

//      提示:
//          1 <= nums.length <= 104
//          0 <= nums[i] <= 1000

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int CanJumpII_A(vector<int> nums);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> arr = generateRandomVec(0, 5, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    printf("到达数组的最后一个位置 最少 需要跳跃 %d 次。\n", CanJumpII_A(arr));
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

int CanJumpII_A(vector<int> nums)
{
    int maxRange = 0;    // 目前为止 所能到达 的 最右边界
    int curMaxRange = 0; // 到达 maxRange 之前所能 到达的 最右边界，用来更新maxRange
    int steps = 0;       // 记录 所用步数

    for (int i = 0; i < nums.size() - 1; i++)
    {
        curMaxRange = max(curMaxRange, i + nums[i]);
        if (i == maxRange)
        {
            maxRange = curMaxRange;
            steps++;
        }
    }
    return steps;
}