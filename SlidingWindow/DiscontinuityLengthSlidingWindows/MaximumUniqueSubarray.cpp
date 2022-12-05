#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      LeetCode  1695. 删除子数组的最大得分

//      链接：https://leetcode.cn/problems/maximum-erasure-value/

//      给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。
//      删除子数组的 得分 就是子数组各元素之 和 。
//      返回 只删除一个 子数组可获得的 最大得分 。
//      如果数组 b 是数组 a 的一个连续子序列，
//      即如果它等于 a[l],a[l+1],...,a[r]，那么它就是 a 的一个子数组。

//      示例 1：
//          输入：nums = [4,2,4,5,6]
//          输出：17
//          解释：最优子数组是 [2,4,5,6]
//      示例 2：
//          输入：nums = [5,2,1,2,5,2,1,2,5]
//          输出：8
//          解释：最优子数组是 [5,2,1] 或 [1,2,5]
//      提示：
//          1 <= nums.length <= 105
//          1 <= nums[i] <= 104

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int MaximumUniqueSubarray(vector<int> &nums);

int main()
{
    int n = generateRandomNum(0, 30);
    int k = generateRandomNum(0, n);
    vector<int> arr = generateRandomVec(1, 10, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans = MaximumUniqueSubarray(arr);
    printf("只删除一个 子数组可获得的 最大得分 %d", ans);
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

// 滑动窗口：
// Time: O(n)
// Space: O(1)
int MaximumUniqueSubarray(vector<int> &nums)
{
    unordered_map<int, int> hmap;
    int l = nums.size();
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;

    while (right < l)
    {
        sum += nums[right];
        hmap[nums[right]]++;
        while (hmap[nums[right]] > 1)
        {
            hmap[nums[left]]--;
            if (hmap[nums[left]] == 0)
            {
                hmap.erase(nums[left]);
            }
            sum -= nums[left];
            left++;
        }
        ans = max(ans, sum);
        right++;
    }
    return ans;
}