#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode 2799. 统计完全子数组的数目

//      链接：https://leetcode.cn/problems/count-complete-subarrays-in-an-array/

//      给你一个由 正 整数组成的数组 nums 。
//      如果数组中的某个子数组满足下述条件，则称之为 完全子数组 ：
//      子数组中 不同 元素的数目等于整个数组不同元素的数目。
//      返回数组中 完全子数组 的数目。
//      子数组 是数组中的一个连续非空序列。
//      示例 1：
//          输入：nums = [1,3,1,2,2]
//          输出：4
//          解释：完全子数组有：[1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2] 。
//      示例 2：
//          输入：nums = [5,5,5,5]
//          输出：10
//          解释：数组仅由整数 5 组成，所以任意子数组都满足完全子数组的条件。子数组的总数为 10 。
//      提示：
//          1 <= nums.length <= 1000
//          1 <= nums[i] <= 2000

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int CountCompleteSubarrays(vector<int>& nums);

int main()
{
    int n = generateRandomNum(0, 50);
    vector<int> vec = generateRandomVec(0, 5, n);
    printVecElement(vec);
    int v = (rand() % vec.size());
    int target = vec[v];
    printf("target 为 %d\n", target);
    vector<int> ans = RemoveElement(vec, target);
    printVecElement(ans);
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

// 滑动窗口：
// Time: O(n)
// Space: O(1)
int CountCompleteSubarrays(vector<int>& nums)
{

}