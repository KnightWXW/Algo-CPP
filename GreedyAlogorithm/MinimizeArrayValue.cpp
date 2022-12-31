#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 2439. 最小化数组中的最大值

//      链接：https://leetcode.cn/problems/minimize-maximum-of-array/

//      给你一个下标从 0 开始的数组 nums ，它含有 n 个非负整数。
//      每一步操作中，你需要：
//      选择一个满足 1 <= i < n 的整数 i ，且 nums[i] > 0 。
//          将 nums[i] 减 1 。
//          将 nums[i - 1] 加 1 。
//      你可以对数组执行 任意 次上述操作，
//      请你返回可以得到的 nums 数组中 最大值 最小 为多少。
//      示例 1：
//          输入：nums = [3,7,1,6]
//          输出：5
//          解释：
//              一串最优操作是：
//              1. 选择 i = 1 ，nums 变为 [4,6,1,6] 。
//              2. 选择 i = 3 ，nums 变为 [4,6,2,5] 。
//              3. 选择 i = 1 ，nums 变为 [5,5,2,5] 。
//              nums 中最大值为 5 。无法得到比 5 更小的最大值。
//              所以我们返回 5 。
//      示例 2：
//          输入：nums = [10,1]
//          输出：10
//          解释：
//              最优解是不改动 nums ，10 是最大值，所以返回 10 。
//      提示：
//          n == nums.length
//          2 <= n <= 105
//          0 <= nums[i] <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int MinimizeArrayValue(vector<int>& nums);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> arr = generateRandomVec(1, 5, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans = MinimizeArrayValue(arr);
    printf("可以得到的 nums 数组中 最大值 最小 为多少 %d。\n", ans);
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
