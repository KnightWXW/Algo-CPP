#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//      LeetCode 2441. 与对应负数同时存在的最大正整数

//      链接：https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/

//      给你一个 不包含 任何零的整数数组 nums，
//      找出自身与对应的负数都在数组中存在的最大正整数 k。
//      返回正整数 k，如果不存在这样的整数，返回 -1。
//      示例 1：
//          输入：nums = [-1,2,-3,3]
//          输出：3
//          解释：3 是数组中唯一一个满足题目要求的 k 。
//      示例 2：
//          输入：nums = [-1,10,6,7,-7,1]
//          输出：7
//          解释：数组中存在 1 和 7 对应的负数，7 的值更大。
//      示例 3：
//          输入：nums = [-10,8,6,7,-2,-3]
//          输出：-1
//          解释：不存在满足题目要求的 k ，返回 -1 。
//      提示：
//          1 <= nums.length <= 1000
//          -1000 <= nums[i] <= 1000
//          nums[i] != 0

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int LargestPositiveIntegerWithNegativend_A(vector<int> &nums);
int LargestPositiveIntegerWithNegativend_B(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec_A = generateRandomVec(-100, 100, n);
    printVecElement(vec_A);
    int ans_A = LargestPositiveIntegerWithNegativend_A(vec_A);
    int ans_B = LargestPositiveIntegerWithNegativend_B(vec_A);
    printf("自身与对应的负数都在数组中存在的最大正整数 为 %d\n", ans_A);
    printf("自身与对应的负数都在数组中存在的最大正整数 为 %d\n", ans_B);
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

int LargestPositiveIntegerWithNegativend_A(vector<int> &nums)
{
    int l = nums.size();
    unordered_set<int> hset;
    int ans = -1;
    for (int i = 0; i < l; i++)
    {
        if (hset.count(-nums[i]) > 0 && abs(nums[i]) > ans)
        {
            ans = abs(nums[i]);
        }
        hset.insert(nums[i]);
    }
    return ans;
}

int LargestPositiveIntegerWithNegativend_B(vector<int> &nums)
{
    vector<int> arr(nums);
    int l = arr.size();
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = l - 1;
    while (left < right && arr[left] < 0 && arr[right] > 0)
    {
        if (arr[left] + arr[right] == 0)
        {
            return arr[right];
        }
        else if (arr[left] + arr[right] < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return -1;
}