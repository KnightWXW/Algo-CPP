#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 1365. 有多少小于当前数字的数字

//      链接：https://leetcode.cn/problems/how-many-numbers-are-smaller-than-the-current-number/

//      给你一个数组 nums，对于其中每个元素 nums[i]，
//      请你统计数组中比它小的所有数字的数目。
//      换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，
//      其中 j 满足 j != i 且 nums[j] < nums[i] 。
//      以数组形式返回答案。
//      示例 1：
//          输入：nums = [8,1,2,2,3]
//          输出：[4,0,1,1,3]
//          解释：
//              对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。
//              对于 nums[1]=1 不存在比它小的数字。
//              对于 nums[2]=2 存在一个比它小的数字：（1）。
//              对于 nums[3]=2 存在一个比它小的数字：（1）。
//              对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
//      示例 2：
//          输入：nums = [6,5,4,8]
//          输出：[2,1,0,3]
//      示例 3：
//          输入：nums = [7,7,7,7]
//          输出：[0,0,0,0]
//      提示：
//          2 <= nums.length <= 500
//          0 <= nums[i] <= 100

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

vector<int> SmallerNumbersThanCurrent_A(vector<int> &nums);
vector<int> SmallerNumbersThanCurrent_B(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> arr = generateRandomVec(1, 5, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    vector<int> ans_A = SmallerNumbersThanCurrent_A(arr);
    vector<int> ans_B = SmallerNumbersThanCurrent_A(arr);
    printf("统计数组中比它 每个元素 小 的所有数字的数目 为:\n");
    printVecElement(ans_A);
    printVecElement(ans_B);
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

// 二分查找：
// Time：O(NlogN)
// Space: O(N)
vector<int> SmallerNumbersThanCurrent_A(vector<int> &nums)
{
    int l = nums.size();
    vector<int> ans(l, 0);
    vector<int> vec(nums.begin(), nums.end());
    sort(vec.begin(), vec.end());
    for (int i = 0; i < l; i++)
    {
        int target = nums[i];
        int left = 0;
        int right = l - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (vec[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        ans[i] = left;
    }
    return ans;
}

// 计数排序：
// Time：O(N^2)
// Space: O(N)
vector<int> SmallerNumbersThanCurrent_B(vector<int> &nums)
{
    int l = nums.size();
    vector<int> ans(l, 0);
    // vector<int> vec(nums.begin(), nums.end());
    //  sort(vec.begin(), vec.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    vector<int> cnt(maxVal + 1, 0);
    for (int i = 0; i < l; i++)
    {
        cnt[nums[i]]++;
    }
    for (int i = 1; i < cnt.size(); i++)
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < l; i++)
    {
        if (nums[i] > 0)
        {
            ans[i] = cnt[nums[i] - 1];
        }
    }
    return ans;
}