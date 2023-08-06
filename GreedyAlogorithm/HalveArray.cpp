#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

//      LeetCode 2208. 将数组和减半的最少操作次数

//      链接：https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/

//      给你一个正整数数组 nums 。
//      每一次操作中，你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。
//      （注意，在后续操作中你可以对减半过的数继续执行操作）
//      请你返回将 nums 数组和 至少 减少一半的 最少 操作数。
//      示例 1：
//          输入：nums = [5,19,8,1]
//          输出：3
//          解释：初始 nums 的和为 5 + 19 + 8 + 1 = 33 。
//              以下是将数组和减少至少一半的一种方法：
//              选择数字 19 并减小为 9.5 。
//              选择数字 9.5 并减小为 4.75 。
//              选择数字 8 并减小为 4 。
//              最终数组为 [5, 4.75, 4, 1] ，和为 5 + 4.75 + 4 + 1 = 14.75 。
//              nums 的和减小了 33 - 14.75 = 18.25 ，
//              减小的部分超过了初始数组和的一半，18.25 >= 33/2 = 16.5 。
//              我们需要 3 个操作实现题目要求，所以返回 3 。
//              可以证明，无法通过少于 3 个操作使数组和减少至少一半。
//      示例 2：
//          输入：nums = [3,8,20]
//          输出：3
//          解释：初始 nums 的和为 3 + 8 + 20 = 31 。
//              以下是将数组和减少至少一半的一种方法：
//              选择数字 20 并减小为 10 。
//              选择数字 10 并减小为 5 。
//              选择数字 3 并减小为 1.5 。
//              最终数组为 [1.5, 8, 5] ，和为 1.5 + 8 + 5 = 14.5 。
//              nums 的和减小了 31 - 14.5 = 16.5 ，减小的部分超过了初始数组和的一半，
//              16.5 >= 31/2 = 15.5 。
//              我们需要 3 个操作实现题目要求，所以返回 3 。
//              可以证明，无法通过少于 3 个操作使数组和减少至少一半。
//      提示：
//          1 <= nums.length <= 105
//          1 <= nums[i] <= 107

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

int HalveArray(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(0, 100, n);
    printVecElement(vec);
    int ans = HalveArray(vec);
    printf("将 nums 数组和 至少 减少一半的 最少 操作数 为 %d \n", ans);
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
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int HalveArray(vector<int> &nums)
{
    int ans = 0;
    double targetSum = accumulate(nums.begin(), nums.end(), 0.0);
    priority_queue<double> pq(nums.begin(), nums.end());
    targetSum /= 2;
    while (targetSum > 0.0)
    {
        double tem = pq.top() / 2;
        pq.pop();
        targetSum -= tem;
        pq.push(tem);
        ans++;
    }
    return ans;
}