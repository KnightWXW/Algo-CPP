#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 1760. 袋子里最少数目的球

//      链接：https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/

//      给你一个整数数组 nums ，其中 nums[i] 表示第 i 个袋子里球的数目。
//      同时给你一个整数 maxOperations 。
//      你可以进行如下操作至多 maxOperations 次：
//      选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 正整数 个球。
//      比方说，一个袋子里有 5 个球，你可以把它们分到两个新袋子里，
//      分别有 1 个和 4 个球，或者分别有 2 个和 3 个球。
//      你的开销是单个袋子里球数目的 最大值 ，你想要 最小化 开销。
//      请你返回进行上述操作后的最小开销。
//      示例 1：
//          输入：nums = [9], maxOperations = 2
//          输出：3
//          解释：
//              - 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[9] -> [6,3] 。
//              - 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[6,3] -> [3,3,3] 。
//              装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
//      示例 2：
//          输入：nums = [2,4,8,2], maxOperations = 4
//          输出：2
//          解释：
//              - 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。
//                  [2,4,8,2] -> [2,4,4,4,2] 。
//              - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。
//                  [2,4,4,4,2] -> [2,2,2,4,4,2] 。
//              - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。
//                  [2,2,2,4,4,2] -> [2,2,2,2,2,4,2] 。
//              - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。
//                  [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2] 。
//              装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
//      示例 3：
//          输入：nums = [7,17], maxOperations = 2
//          输出：7
//      提示：
//          1 <= nums.length <= 105
//          1 <= maxOperations, nums[i] <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int MinimumSize(vector<int> &nums, int maxOperations);
bool JudgeMinimumSize_A(vector<int> &nums, int maxOperations, int cur);
bool JudgeMinimumSize_B(vector<int> &nums, int maxOperations, int cur);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(1, 100, n);
    int maxOperations = generateRandomNum(1, 2 * n);
    printVec(vec);
    int ans = MinimumSize(vec, maxOperations);
    printf("进行下操作至多 %d 次，最小化 开销为 %d", maxOperations, ans);
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
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int MinimumSize(vector<int> &nums, int maxOperations)
{
    int l = nums.size();
    int left = 1;
    int right = *max_element(nums.begin(), nums.end());
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeMinimumSize_A(nums, maxOperations, mid))
        // if (JudgeMinimumSize_B(nums, maxOperations, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

bool JudgeMinimumSize_A(vector<int> &nums, int maxOperations, int cur)
{
    int l = nums.size();
    int cnt = 0;
    for (int i = 0; i < l; i++)
    {
        if (nums[i] % cur == 0)
        {
            cnt += (nums[i] / cur - 1);
        }
        else
        {
            cnt += nums[i] / cur;
        }
    }
    return cnt <= maxOperations;
}

bool JudgeMinimumSize_B(vector<int> &nums, int maxOperations, int cur)
{
    int l = nums.size();
    int cnt = 0;
    for (int i = 0; i < l; i++)
    {
        cnt += (nums[i] - 1) / cur;
    }
    return cnt <= maxOperations;
}