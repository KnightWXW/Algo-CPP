#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <float.h>

using namespace std;

//      LeetCode 643. 子数组最大平均数 I

//      链接：https://leetcode.cn/problems/maximum-average-subarray-i/

//      给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
//      请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
//      任何误差小于 10-5 的答案都将被视为正确答案。
//      示例 1：
//          输入：nums = [1,12,-5,-6,50,3], k = 4
//          输出：12.75
//          解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
//      示例 2：
//          输入：nums = [5], k = 1
//          输出：5.00000
//      提示：
//          n == nums.length
//          1 <= k <= n <= 105
//          -104 <= nums[i] <= 104

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

double FindMaxAverage(vector<int> &nums, int k);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(0, 20, n);
    int k = generateRandomNum(1, n);
    printVecElement(vec);
    double ans = FindMaxAverage(vec, k);
    printf("平均数最大 且 长度为 %d 的连续子数组，该最大平均数为 %f\n", k, ans);
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

double FindMaxAverage(vector<int> &nums, int k)
{
    int l = nums.size();
    int left = 0;
    int right = 0;
    double sum = 0;
    double ans = -DBL_MAX;

    while (right < l)
    {
        sum += nums[right];
        while (right - left + 1 > k)
        {
            sum -= nums[left];
            left++;
        }
        if (right - left + 1 == k)
        {
            ans = max(ans, sum);
        }
        right++;
    }
    return ans / k;
}