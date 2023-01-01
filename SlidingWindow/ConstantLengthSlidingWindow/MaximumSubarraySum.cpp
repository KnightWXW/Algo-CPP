#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      LeetCode 2461. 长度为 K 子数组中的最大和

//      链接：https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/

//      给你一个整数数组 nums 和一个整数 k 。
//      请你从 nums 中满足下述条件的全部子数组中找出最大子数组和：
//      子数组的长度是 k，且
//      子数组中的所有元素 各不相同 。
//      返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 0 。
//      子数组 是数组中一段连续非空的元素序列。
//      示例 1：
//          输入：nums = [1,5,4,2,9,9,9], k = 3
//          输出：15
//          解释：nums 中长度为 3 的子数组是：
//          - [1,5,4] 满足全部条件，和为 10 。
//          - [5,4,2] 满足全部条件，和为 11 。
//          - [4,2,9] 满足全部条件，和为 15 。
//          - [2,9,9] 不满足全部条件，因为元素 9 出现重复。
//          - [9,9,9] 不满足全部条件，因为元素 9 出现重复。
//          因为 15 是满足全部条件的所有子数组中的最大子数组和，所以返回 15 。
//      示例 2：
//          输入：nums = [4,4,4], k = 3
//          输出：0
//          解释：nums 中长度为 3 的子数组是：
//          - [4,4,4] 不满足全部条件，因为元素 4 出现重复。
//          因为不存在满足全部条件的子数组，所以返回 0 。
//      提示：
//          1 <= k <= nums.length <= 105
//          1 <= nums[i] <= 105

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

long long maximumSubarraySum(vector<int> &nums, int k);

int main()
{
    int n = generateRandomNum(1, 30);
    int k = generateRandomNum(1, n / 2 + 1);
    vector<int> arr = generateRandomVec(0, 20, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    long long ans = maximumSubarraySum(arr, k);
    printf("长度是 %d 的 最大子数组和为 %lld", k, ans);
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

long long maximumSubarraySum(vector<int> &nums, int k)
{
    int l = nums.size();
    unordered_map<int, int> hmap;
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        hmap[nums[i]]++;
        sum += nums[i];
    }

    if (hmap.size() == k)
    {
        ans = max(ans, sum);
    }

    for (int i = 0; i < l - k; i++)
    {
        hmap[nums[i]]--;
        sum -= nums[i];
        if (hmap[nums[i]] == 0)
        {
            hmap.erase(nums[i]);
        }

        hmap[nums[i + k]]++;
        sum += nums[i + k];

        if (hmap.size() == k)
        {
            ans = max(ans, sum);
        }
    }
    return ans;
}