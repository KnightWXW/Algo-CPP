#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 1438. 绝对差不超过限制的最长连续子数组

//      链接：https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

//      给你一个整数数组 nums ，和一个表示限制的整数 limit，
//      请你返回最长连续子数组的长度，
//      该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit 。
//      如果不存在满足条件的子数组，则返回 0 。

//      示例 1：
//          输入：nums = [8,2,4,7], limit = 4
//          输出：2 
//          解释：所有子数组如下：
//          [8] 最大绝对差 |8-8| = 0 <= 4.
//          [8,2] 最大绝对差 |8-2| = 6 > 4. 
//          [8,2,4] 最大绝对差 |8-2| = 6 > 4.
//          [8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
//          [2] 最大绝对差 |2-2| = 0 <= 4.
//          [2,4] 最大绝对差 |2-4| = 2 <= 4.
//          [2,4,7] 最大绝对差 |2-7| = 5 > 4.
//          [4] 最大绝对差 |4-4| = 0 <= 4.
//          [4,7] 最大绝对差 |4-7| = 3 <= 4.
//          [7] 最大绝对差 |7-7| = 0 <= 4. 
//          因此，满足题意的最长子数组的长度为 2 。
//      示例 2：
//          输入：nums = [10,1,2,4,7,2], limit = 5
//          输出：4 
//          解释：满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 <= 5 。
//      示例 3：
//          输入：nums = [4,2,2,2,4,4,2,2], limit = 0
//          输出：3
//      提示：
//          1 <= nums.length <= 10^5
//          1 <= nums[i] <= 10^9
//          0 <= limit <= 10^9

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int LongestSubarray(vector<int>& nums, int limit);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> arr = generateRandomVec(0, 1, n);
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int limit = generateRandomNum(minVal, maxVal);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    printf("子数组中的任意两个元素之间的绝对差必须小于或者等于 %d 时\n, 最长连续子数组的长度 %d", limit, ans);
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

int LongestSubarray(vector<int>& nums, int limit){
    
}