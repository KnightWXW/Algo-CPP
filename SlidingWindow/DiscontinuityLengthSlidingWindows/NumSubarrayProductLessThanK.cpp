#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      LeetCode 713. 乘积小于 K 的子数组

//      链接 1 : https://leetcode.cn/problems/subarray-product-less-than-k/
//      链接 2 : https://leetcode.cn/problems/ZVAVXX/

//      给你一个整数数组 nums 和一个整数 k ，
//      请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
//      示例 1：
//              输入：nums = [10,5,2,6], k = 100
//              输出：8
//              解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
//                   需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
//      示例 2：
//          输入：nums = [1,2,3], k = 0
//          输出：0
//      提示:
//          1 <= nums.length <= 3 * 104
//          1 <= nums[i] <= 1000
//          0 <= k <= 106

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int NumSubarrayProductLessThanK(vector<int> &nums, int k);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 20, n);
    int k = generateRandomNum(0, 100);
    printVecElement(vec);
    int ans = NumSubarrayProductLessThanK(vec, k);
    printf("子数组内所有元素的乘积严格小于 %d 的连续子数组的数目为 %d.\n", k, ans);
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

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 滑动窗口：
// Time: O(N)
// Space: O(1)
int NumSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int l = nums.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    int mul = 1;
    while (right < l)
    {
        mul *= nums[right];
        while (left <= right && mul >= k)
        {
            mul /= nums[left];
            left++;
        }
        ans += (right - left + 1);
        right++;
    }
    return ans;
}