#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>

using namespace std;

//      LeetCode 209. 长度最小的子数组

//      链接：https://leetcode.cn/problems/minimum-size-subarray-sum/

//      给定一个含有 n 个正整数的数组和一个正整数 target 。
//      找出该数组中满足其和 ≥ target 的长度最小的 连续子数组[numsl, numsl+1, ..., numsr-1, numsr]，
//      并返回其长度。
//      如果不存在符合条件的子数组，返回 0 。

//      示例 1：
//          输入：target = 7, nums = [2,3,1,2,4,3]
//          输出：2
//          解释：子数组 [4,3] 是该条件下的长度最小的子数组。
//      示例 2：
//          输入：target = 4, nums = [1,4,4]
//          输出：1
//      示例 3：
//          输入：target = 11, nums = [1,1,1,1,1,1,1,1]
//          输出：0
//      提示：
//          1 <= target <= 109
//          1 <= nums.length <= 105
//          1 <= nums[i] <= 105

// 进阶：如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int MinSubArrayLen(int target, vector<int> &nums);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> vec = generateRandomVec(0, 20, n);
    int sum = accumulate(vec.begin(), vec.end(), 0);
    int target = generateRandomNum(0, sum);
    printVecElement(vec);
    int ans = MinSubArrayLen(target, vec);
    printf("满足其和 ≥ %d 的长度最小的 连续子数组长度为 %d\n", target, ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
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

int MinSubArrayLen(int target, vector<int> &nums)
{
    int l = nums.size();
    int left = 0;
    int right = 0;
    int ans = l + 1;
    int sum = 0;

    while (right < l)
    {
        sum += nums[right];
        while (sum >= target)
        {
            ans = min(right - left + 1, ans);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    if (ans == l + 1)
    {
        return 0;
    }
    return ans;
}