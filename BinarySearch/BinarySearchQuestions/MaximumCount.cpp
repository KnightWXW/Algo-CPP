#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      LeetCode 2529. 正整数和负整数的最大计数

//      链接：https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/

//      给你一个按 非递减顺序 排列的数组 nums ，返回正整数数目和负整数数目中的最大值。
//      换句话讲，如果 nums 中正整数的数目是 pos ，
//      而负整数的数目是 neg ，返回 pos 和 neg二者中的最大值。
//      注意：0 既不是正整数也不是负整数。
//      示例 1：
//          输入：nums = [-2,-1,-1,1,2,3]
//          输出：3
//          解释：共有 3 个正整数和 3 个负整数。计数得到的最大值是 3 。
//      示例 2：
//          输入：nums = [-3,-2,-1,0,0,1,2]
//          输出：3
//          解释：共有 2 个正整数和 3 个负整数。计数得到的最大值是 3 。
//      示例 3：
//          输入：nums = [5,20,66,1314]
//          输出：4
//          解释：共有 4 个正整数和 0 个负整数。计数得到的最大值是 4 。
//      提示：
//          1 <= nums.length <= 2000
//          -2000 <= nums[i] <= 2000
//          nums 按 非递减顺序 排列。
//          进阶：你可以设计并实现时间复杂度为 O(log(n)) 的算法解决此问题吗？

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int MaximumCount_A(vector<int> &nums);
int MaximumCount_B(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(-5, 5, n);
    sort(vec.begin(), vec.end());
    int ans_A = MaximumCount_A(vec);
    int ans_B = MaximumCount_B(vec);
    printVecElement(vec);
    printf("数组中正整数数目和负整数数目中的最大值是 %d\n", ans_A);
    printf("数组中正整数数目和负整数数目中的最大值是 %d\n", ans_B);
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

// 遍历：
// Time: O(n)
// Space: O(1)
int MaximumCount_A(vector<int> &nums)
{
    int pos = 0;
    int neg = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            pos++;
        }
        else if (nums[i] < 0)
        {
            neg++;
        }
    }
    return max(pos, neg);
}

// 二分查找：
// Time: O(logN)
// Space: O(1)
int HelperMaximumCount_B(vector<int> &nums, int k)
{
    int l = nums.size();
    int left = 0;
    int right = l - 1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] >= k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int MaximumCount_B(vector<int> &nums)
{
    int l = nums.size();
    int indexPos = HelperMaximumCount_B(nums, 1);
    int pos = l - indexPos; 
    int indexNeg = HelperMaximumCount_B(nums, 0);
    int neg = indexNeg;
    return max(pos, neg);
}