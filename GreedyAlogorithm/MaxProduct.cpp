#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 152. 乘积最大子数组

//      链接：https://leetcode.cn/problems/maximum-product-subarray/

//      给你一个整数数组 nums，请你找出数组中乘积最大的非空连续子数组
//     （该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//      测试用例的答案是一个 32-位 整数。
//      子数组 是数组的连续子序列。
//      示例 1:
//          输入: nums = [2,3,-2,4]
//          输出: 6
//          解释: 子数组 [2,3] 有最大乘积 6。
//      示例 2:
//          输入: nums = [-2,0,-1]
//          输出: 0
//          解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
//      提示:
//          1 <= nums.length <= 2 * 104
//          -10 <= nums[i] <= 10
//          nums 的任何前缀或后缀的乘积都 保证 是一个 32-位 整数

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int MaxProduct(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(-100, 100, n);
    printVec(vec);
    int ans = MaxProduct(vec);
    printf("乘积最大的非空连续子数组的 最大乘积 为: %d\n", ans);
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

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int MaxProduct(vector<int> &nums)
{
    int l = nums.size();
    int maxVal = nums[0];
    int minVal = nums[0];
    int ans = nums[0];
    for (int i = 1; i < l; i++)
    {
        int maxTem = maxVal;
        int minTem = minVal;
        maxVal = max(nums[i], max(maxTem * nums[i], minTem * nums[i]));
        minVal = min(nums[i], min(maxTem * nums[i], minTem * nums[i]));
        ans = max(ans, maxVal);
    }
    return ans;
}