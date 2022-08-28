#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 53. 最大子数组和

//      链接：https://leetcode.cn/problems/maximum-subarray/

//      给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
//      返回其最大和。
//      子数组 是数组中的一个连续部分。

//      示例 1：
//      输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//      输出：6
//      解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

//      示例 2：
//      输入：nums = [1]
//      输出：1

//      示例 3：
//      输入：nums = [5,4,-1,7,8]
//      输出：23

//      提示：
//      1 <= nums.length <= 105
//      -104 <= nums[i] <= 104

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int maxSubArray_A(vector<int> vec);
int dfsMaxSubArray_A(vector<int> vec, int index);
int maxSubArray_B(vector<int> vec);
int dfsMaxSubArray_B(vector<int> vec, int index, vector<int> &arr);
int maxSubArray_C(vector<int> vec);
int maxSubArray_D(vector<int> vec);
int maxSubArray_E(vector<int> vec);
int main()
{
    int n = generateRandomNum(0, 20);
    vector<int> vec = generateRandomVec(-100, 100, n);
    printVecElement(vec);
    printf("(暴力递归)连续子数组的最大和为 %d \n", maxSubArray_A(vec));
    printf("(记忆化搜索)连续子数组的最大和为 %d \n", maxSubArray_B(vec));
    printf("(动态规划)连续子数组的最大和为 %d \n", maxSubArray_C(vec));
    printf("(动态规划[空间压缩])连续子数组的最大和为 %d \n", maxSubArray_D(vec));
    printf("(贪心算法)连续子数组的最大和为 %d \n", maxSubArray_E(vec));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
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

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int maxSubArray_A(vector<int> vec)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < vec.size(); i++)
    {
        maxSum = max(maxSum, dfsMaxSubArray_A(vec, i));
    }
    return maxSum;
}

int dfsMaxSubArray_A(vector<int> vec, int index)
{
    if (index >= vec.size())
    {
        return 0;
    }
    // 从 vec[index] 开始 最大值, 要么一致加下去，要么 重新开始计算
    return max(vec[index], vec[index] + dfsMaxSubArray_A(vec, index + 1));
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int maxSubArray_B(vector<int> vec)
{
    int maxSum = INT_MIN;
    int l = vec.size();
    vector<int> arr(l + 1, INT_MIN);
    int k = dfsMaxSubArray_B(vec, 0, arr);

    for (int i = 0; i <= vec.size(); i++)
    {
        maxSum = max(maxSum, arr[i]);
    }
    return maxSum;
}

int dfsMaxSubArray_B(vector<int> vec, int index, vector<int> &arr)
{
    if (index >= vec.size())
    {
        return 0;
    }
    if (arr[index] != INT_MIN)
    {
        return arr[index];
    }
    // 从 vec[index] 开始 最大值, 要么一致加下去，要么 重新开始计算
    arr[index] = max(vec[index], vec[index] + dfsMaxSubArray_B(vec, index + 1, arr));
    return arr[index];
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int maxSubArray_C(vector<int> vec)
{
    int maxSum = INT_MIN;
    int l = vec.size();

    vector<int> dp(l + 1, 0);
    dp[1] = vec[0];
    for (int i = 1; i <= l; i++)
    {
        dp[i] = max(dp[i - 1] + vec[i - 1], vec[i - 1]);
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}

// 动态规划[空间压缩]：
// Time: O(N)
// Space: O(1)
int maxSubArray_D(vector<int> vec)
{
    int maxSum = INT_MIN;
    int sum = 0;
    int l = vec.size();
    for (int i = 0; i < l; i++)
    {
        sum = max(sum + vec[i], vec[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// 贪心算法：
// Time: O(N)
// Space: O(1)
int maxSubArray_E(vector<int> vec)
{
    int maxSum = INT_MIN;
    int sum = 0;
    int l = vec.size();
    for (int i = 0; i < l; i++)
    {
        if (sum < 0)
        {
            sum = vec[i];
        }
        else
        {
            sum += vec[i];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}